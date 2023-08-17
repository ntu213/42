FROM	debian:buster

RUN		apt-get update -yq && apt-get install -yq nginx openssl

RUN		mkdir -p /etc/nginx/ssl
RUN		openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
		-out /etc/nginx/ssl/nginx.pem \
		-keyout /etc/nginx/ssl/nginx.key \
		-subj "/C=FR/ST=Perpignan/L=Perpignan/O=Perpignan/OU=vgiraudo/CN=${DOMAIN_NAME}/"

RUN		mkdir -p /files

COPY	setup.sh /files/setup.sh
RUN		chmod +x /files/setup.sh

RUN		mkdir -p /files/game
COPY	./game/* /files/game/

EXPOSE	443

ENTRYPOINT	["/files/setup.sh"]

CMD			["nginx", "-g", "daemon off;"]
