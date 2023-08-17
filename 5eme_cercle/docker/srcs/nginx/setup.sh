#!/bin/sh

echo "
server {
	include /etc/nginx/mime.types;
	listen 443 ssl;
	listen [::]:443 ssl;

	server_name ${DOMAIN_NAME};

	ssl_certificate /etc/nginx/ssl/nginx.pem;
	ssl_certificate_key /etc/nginx/ssl/nginx.key;
	ssl_protocols TLSv1.2 TLSv1.3;

	index	index.php;
	root	/var/www/html/;

	access_log /var/log/nginx/access.log;
	error_log /var/log/nginx/error.log;
	
	location / {
	 	try_files \$uri \$uri/ /index.php?\$args;
	}

	location ~ \.php$ {
		fastcgi_split_path_info ^(.+\.php)(/.+)$;
		fastcgi_pass ${PHP_ADDR}:${PHP_PORT};
		fastcgi_index index.php;
		include fastcgi_params;
		fastcgi_param SCRIPT_FILENAME \$document_root\$fastcgi_script_name;
		fastcgi_param PATH_INFO \$fastcgi_path_info;
	}
}
" > /etc/nginx/sites-enabled/default

mkdir	-p /var/www/html/game
cp	-r /files/game/* /var/www/html/game/

echo Start Nginx
exec "$@"
