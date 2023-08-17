echo "
CREATE DATABASE $MAR_DB;
CREATE USER '$MAR_USER'@'%' IDENTIFIED BY '$MAR_PASS';
GRANT ALL PRIVILEGES ON $MAR_DB.* TO '$MAR_USER'@'%' IDENTIFIED BY '$MAR_PASS';
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MAR_R_PASS';
FLUSH PRIVILEGES;
" > /files/init.sql

echo "
[mysqld]
port=$MAR_PORT
bind-address=0.0.0.0
" > /etc/mysql/my.cnf

if [ -d "/data/mysql/$MAR_DB" ]
then
        echo "Mariadb start."
        mysqld_safe --user=mysql
else
        echo "Mariadb install."
        mysql_install_db --basedir=/usr --user=mysql --datadir=/data/mysql
        echo "Mariadb first start."
        mysqld --user=mysql --init-file="/files/init.sql"
fi

exec /usr/bin/mysql --user=mysql
