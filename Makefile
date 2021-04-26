start_ssh: transfer
	sshpass -p "xinurocks" ssh xinu@localhost -p 2222 "rm -rf assistant && tar -xf xinupro.tar && cd ./assistant/compile && make clean && make && exit"
transfer: zip
	sshpass -p "xinurocks" scp -P 2222 ./xinupro.tar xinu@localhost:/home/xinu/
zip:
	tar -cf xinupro.tar assistant
stop:
	VBoxManage controlvm "backend" poweroff
start:
	VBoxManage startvm "backend" --type headless
vmstart:
	VBoxManage startvm "development-system" --type headless
vmstop:
	VBoxManage controlvm "development-system" poweroff