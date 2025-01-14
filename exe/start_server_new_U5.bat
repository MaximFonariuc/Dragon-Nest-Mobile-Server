echo off
echo start

setlocal

set /p update-res=Uploud current tables(1:YES,0:NO):

if "%update-res%" == "1" (

echo  "Check tables path"

rmdir /s/q gsconf\table

rmdir /s/q gsconf\Curve
rmdir /s/q gsconf\SkillPackage
rmdir /s/q gsconf\CutScene

echo "Upload tables"

mkdir gsconf\table
mkdir gsconf\table\AITree
mkdir gsconf\table\Level
mkdir gsconf\table\SceneBlock
mkdir gsconf\table\WayPoint
mkdir gsconf\table\SuperRisk

mkdir gsconf\CutScene
mkdir gsconf\SkillPackage
mkdir gsconf\Curve
 
xcopy /e /exclude:exclude.txt D:\Git\SoloProjects\DragonNestM\XProject\Assets\Table gsconf\table\
xcopy /e /exclude:exclude.txt D:\Git\SoloProjects\DragonNestM\XProject\Assets\Resources\Table\AITree gsconf\table\AITree
xcopy /e /exclude:exclude.txt D:\Git\SoloProjects\DragonNestM\XProject\Assets\Resources\Table\Level gsconf\table\Level
xcopy /e /exclude:exclude.txt D:\Git\SoloProjects\DragonNestM\XProject\Assets\Resources\Table\SceneBlock gsconf\table\SceneBlock
xcopy /e /exclude:exclude.txt D:\Git\SoloProjects\DragonNestM\XProject\Assets\Resources\Table\WayPoint gsconf\table\WayPoint
xcopy /e /exclude:exclude.txt D:\Git\SoloProjects\DragonNestM\XProject\Assets\Resources\Table\SuperRisk gsconf\table\SuperRisk

xcopy /e /exclude:exclude.txt D:\Git\SoloProjects\DragonNestM\XProject\Assets\Resources\CutScene gsconf\CutScene\
xcopy /e /exclude:exclude.txt D:\Git\SoloProjects\DragonNestM\XProject\Assets\Resources\SkillPackage gsconf\SkillPackage\
xcopy /e /exclude:exclude.txt D:\Git\SoloProjects\DragonNestM\XProject\Assets\Editor\EditorResources\Server\Curve gsconf\Curve\

)

endlocal

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
pause
