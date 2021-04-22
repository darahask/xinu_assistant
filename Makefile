start_ssh: transfer
	sshpass -p "xinurocks" ssh xinu@localhost -p 2222 "tar -xf xinupro.tar && exit"
transfer: zip
	sshpass -p "xinurocks" scp -P 2222 ./xinupro.tar xinu@localhost:/home/xinu/
zip:
	tar -cf xinupro.tar assistant
stop:
	VBoxManage controlvm "backend" poweroff
start:
	VBoxManage startvm "backend" --type headless