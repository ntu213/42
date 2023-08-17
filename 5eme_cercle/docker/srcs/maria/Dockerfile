FROM	debian:buster

RUN		apt-get update -yq
RUN		apt-get install mariadb-server mariadb-client -yq

RUN		mkdir -p /data/mysql && chown -R mysql:mysql /data/mysql
RUN		mkdir -p /files && chown -R mysql:mysql /files
RUN		mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld
RUN		mkdir -p /etc/mysql && chown -R mysql:mysql /etc/mysql
RUN		mkdir -p /var/lib/mysql && chown -R mysql:mysql /var/lib/mysql

COPY	setup.sh /files/setup.sh
RUN		chmod +x /files/setup.sh

ENTRYPOINT	["sh", "/files/setup.sh"]
