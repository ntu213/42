#!bin/sh

echo "
[www]
user  = www-data
group = www-data
listen = $PHP_PORT
listen.owner = www-data
listen.group = www-data
pm = dynamic
pm.max_children = 5
pm.start_servers = 2
pm.min_spare_servers = 1
pm.max_spare_servers = 3
" > /etc/php/7.3/fpm/pool.d/www.conf

if [ -f "/var/www/html/wp-config.php" ]
then
        echo	 "Wordpress installed"
else
        echo	"Wordpress install..."
        wget	 https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
        chmod +x wp-cli.phar
        mv wp-cli.phar /usr/local/bin/wp
        cd /var/www/html
        wp core download --allow-root
        wp core config --allow-root --dbhost=${MAR_ADDR} --dbname=${MAR_DB} --dbuser=${MAR_USER} --dbpass=${MAR_PASS}
        wp core install --allow-root --url=${DOMAIN_NAME} --title=${WRP_NAME} --admin_user=${WRP_R_USER} --admin_password=${WRP_R_PASS} --admin_email=vgiraudo@42.fr
        wp user create --allow-root ${WRP_USER} email@email.email --user_pass=${WRP_PASS};
		wp config --allow-root set WP_DEBUG true
        wp config --allow-root set WP_MEMORY_LIMIT '64M'
        wp plugin --allow-root deactivate --all
        wp config --allow-root set WP_DEBUG_LOG true
fi

echo "
define('WP_REDIS_HOST', 'localhost');
define('WP_REDIS_PORT', 6379);" >> /var/www/html/wp-config.php

echo "
<?php
	header('Location: https://127.0.0.1:1443/game/index.html');
?>" > /var/www/html/index.php

echo "
<?php
	phpinfo();
?>" > /var/www/html/info.php

cd /var/www/html/
wget -P wp-content/plugins/ https://downloads.wordpress.org/plugin/redis-cache.latest-stable.zip
unzip wp-content/plugins/redis-cache.latest-stable.zip -d wp-content/plugins/
chown -R www-data:www-data wp-content/plugins/redis-cache

echo Wordpress start
exec "$@"
