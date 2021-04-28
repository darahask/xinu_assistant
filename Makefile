start_ssh: transfer
	sshpass -p "xinurocks" ssh xinu@localhost -p 2222 "rm -rf dpp && tar -xf xinupro.tar && cd ./dpp/compile && make clean && make && exit"
transfer: zip
	sshpass -p "xinurocks" scp -P 2222 ./xinupro.tar xinu@localhost:/home/xinu/
zip:
	tar -cf xinupro.tar dpp
stop:
	VBoxManage controlvm "backend" poweroff
start:
	VBoxManage startvm "backend" --type headless
vmstart:
	VBoxManage startvm "development-system" --type headless
vmstop:
	VBoxManage controlvm "development-system" poweroff