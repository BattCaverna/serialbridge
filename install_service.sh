#! /bin/bash
set -x

install () {
	service=$1.service
	sudo cp ${service} /lib/systemd/system/
	sudo systemctl daemon-reload
	sudo systemctl enable ${service}
	sudo systemctl start ${service}
}


sudo cp serialbridge /usr/local/bin
install serialbridge
