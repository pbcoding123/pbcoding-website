@echo off
chcp 65001
@echo off
echo =====Open net 2.5=====
echo Create by Pbcoding.
echo.
net session >nul 2>&1
if %errorlevel% neq 0 (
echo 权限不足，需要提升。
echo.
pause
exit
)
echo 正在进行基本操作…… 
sc stop tdnetfilter
sc delete tdnetfilter
taskkill -IM masterhelper.exe -f
sc stop tvnserver
sc stop STUDSRV
sc stop BSAgentSvr
taskkill -IM studentmain.exe -f
taskkill -IM ebClnt.exe -f
taskkill -IM ebMaintain.exe -f
echo 基本操作完成。 
pause
cls
echo 更改DNS......
echo 如果你此时已经可以使用网络了，请关闭。 
echo 如果此时网页还是加载不出来，请继续。 
echo.
pause
netsh interface ipv4 show interface
echo.
set /p str="请输入你看到的<已连接>或<已启用>的适配器名称(可能是WLAN或以太网):"
echo 正在更改适配器"%str%"的DNS......
netsh interface ipv4 set dns name="%str%" static 8.8.8.8
if %errorlevel% neq 0 (
echo 设置失败，请检查网络适配器名称是否正确。
echo.
pause
exit
)
echo 成功更改适配器"%str%"的主DNS为8.8.8.8。 
netsh interface ipv4 add dns name="%str%" 114.114.114.114 index=2
echo 成功更改适配器"%str%"的备用DNS为114.114.114.114。 
echo.
echo 更改完成。 
echo.
timeout /t 5