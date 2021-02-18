#!/bin/bash

service nginx start
service nginx status

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gam/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

mv -f tmp/default ./etc/nginx/sites-available
#mv -f tmp/wp-config.php ./var/www/html/wordpress
#mv -f tmp/config.inc.php ./var/www/html/phpmyadmin

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz


mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress

cp tmp/wp-config.php ./var/www/html/wordpress/wp-config.php

service php7.3-fpm start
service php7.3-fpm status

#touch var/www/html/phpinfo.php
#echo "<?php phpinfo(); ?>" > phpinfo.php
service nginx reload

mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/

cp -rp tmp/config.inc.php ./var/www/html/phpmyadmin/config.inc.php

service nginx reload
service mysql start
service php7.3-fpm restar


mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
mysqladmin -u root -p passoword

mysql << QUERY

show databases;
CREATE DATABASE IF NOT EXISTS wordpress;
show databases;
CREATE USER 'jae-kim'@'localhost' IDENTIFIED BY 'root';
GRANT ALL PRIVILEGES ON wordpress.* TO 'jae-kim'@'localhost' WITH GRANT OPTION;
USE wordpress;
SHOW TABLES;
exit
QUERY


service php7.3-fpm restart
service nginx reload
service mysql start
