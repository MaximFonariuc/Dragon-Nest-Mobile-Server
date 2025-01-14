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


echo "无法查询到你的服务器ID"
echo "服务器开启失败"


REM 暂停2秒钟
REM ping 127.0.0.1 -n 2 > nul 

:exitpoint