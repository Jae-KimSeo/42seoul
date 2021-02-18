FROM debian:buster

LABEL maintainer="jae-kim@student.42seoul.kr"

RUN	apt-get update && apt-get upgrade -y && apt-get install -y \
	nginx \
	openssl \
	vim \ 
	wget \
	php7.3-fpm \
	mariadb-server php-mysql


COPY	./srcs/run.sh ./
COPY 	./srcs/default ./tmp
COPY 	./srcs/wp-config.php ./tmp
COPY 	./srcs/config.inc.php ./tmp

EXPOSE	80 443

CMD		bash run.sh
