echo off

setlocal
endlocal

echo "¿ªÆô·þÎñÆ÷"

start /MIN worldserver.exe conf/world_conf.xml
start /MIN routerserver.exe conf/router_conf.xml
start /MIN gameserver.exe conf/gs_cross_conf.xml

