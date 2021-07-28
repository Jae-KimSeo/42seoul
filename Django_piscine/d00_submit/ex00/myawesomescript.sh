#!/bin/sh

curl -s $1 | grep "a href" | cut -d '"' -f2

