echo off
echo start

echo "Starting Server"

start /MIN audioserver.exe conf/audio_conf.xml
start /MIN loginserver.exe conf/login_conf.xml
start /MIN dbserver.exe conf/db_conf.xml
start /MIN gameserver.exe conf/gs_conf.xml
start /MIN gateserver.exe conf/gate_conf.xml
start /MIN masterserver.exe conf/ms_conf.xml
start /MIN controlserver.exe conf/ctrl_conf.xml
start /MIN versionserver.exe conf/version_conf.xml

goto exitpoint


echo "�޷���ѯ����ķ�����ID"
echo "����������ʧ��"


REM ��ͣ2����
REM ping 127.0.0.1 -n 2 > nul 

:exitpoint