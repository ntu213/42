FROM	debian:buster

RUN		apt-get update -yq
RUN		apt-get install -yq wget mariadb-client php php-mysql php-cli \
		php-mbstring php-fpm php-gettext php7.3 php-mysqli

RUN		mkdir -p /files && mkdir -p /run/php
COPY	setup.sh /files/setup.sh
RUN		chmod +x /files/setup.sh

ENTRYPOINT	["/files/setup.sh"]

CMD			["/usr/sbin/php-fpm7.3", "--nodaemonize"]

