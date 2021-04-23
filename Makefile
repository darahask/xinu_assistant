start-ssh: start_ssh
		sshpass -p 'xinurocks' ssh -o StrictHostKeyChecking=no -t xinu@127.0.0.1 -p 2222
start_ssh: transfer
	sshpass -p "xinurocks" ssh -o StrictHostKeyChecking=no -t  xinu@localhost -p 2222 "tar -xf xinupro.tar && exit"
transfer: zip
	sshpass -p "xinurocks" scp -P 2222 ./xinupro.tar xinu@localhost:/home/xinu/
zip:
	tar -cf xinupro.tar assistant
stop:
	VBoxManage controlvm "backend" poweroff
start:
	VBoxManage startvm "backend" --type headless
