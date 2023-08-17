all: compose_start

compose_start:
	docker-compose -f srcs/docker-compose.yml up --force-recreate;

re: clean
	docker-compose -f srcs/docker-compose.yml down -v
	docker-compose -f srcs/docker-compose.yml build --no-cache
	docker-compose -f srcs/docker-compose.yml up --force-recreate;

clean:
	docker volume prune -f
	docker system prune -a -f
