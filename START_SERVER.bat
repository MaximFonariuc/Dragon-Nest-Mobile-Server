@echo off
echo start

echo "Starting Server"

REM ���֧�֧��� �� ��ѧ�ܧ� exe/
cd exe/

REM ���ѧ���� ��֧�ӧ֧��� �� ��ܧѧ٧ѧߧڧ֧� ����֧� �� �ܧ�ߧ�ڧԧ��ѧ�ڧ�ߧߧ�� ��ѧۧݧѧ�
start /MIN audioserver.exe conf/audio_conf.xml
start /MIN loginserver.exe conf/login_conf.xml
start /MIN dbserver.exe conf/db_conf.xml
start /MIN gameserver.exe conf/gs_conf.xml
start /MIN gateserver.exe conf/gate_conf.xml
start /MIN masterserver.exe conf/ms_conf.xml
start /MIN controlserver.exe conf/ctrl_conf.xml
start /MIN versionserver.exe conf/version_conf.xml

REM ����٧ӧ�ѧ� �� �ܧ��ߧ֧ӧ�� �էڧ�֧ܧ���ڧ�
cd ..

goto exitpoint

echo "�޷���ѯ����ķ�����ID"
echo "����������ʧ��"

REM ���ѧ�٧� �ߧ� 2 ��֧ܧ�ߧէ� (�٧ѧܧ�ާާ֧ߧ�ڧ��ӧѧߧ�)
REM ping 127.0.0.1 -n 2 > nul 

:exitpoint