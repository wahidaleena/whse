#!/bin/sh

. ./environment.cnf

export APPLIC_NAME=whse_rcpt.exec
export DIR_PATH=./

export APP_EXEC=${DIR_PATH}${APPLIC_NAME}


wget -c ftp://$MF_USERr:@$MF_PASSWORD@MFDNT01/$FILENAME

# time ${APP_EXEC}
./whse_rcpt.exec

echo "DONE"
