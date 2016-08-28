@echo off
set RELEASEDIR=.\release
rmdir /S /Q %RELEASEDIR%
mkdir %RELEASEDIR%
mkdir %RELEASEDIR%\x32
mkdir %RELEASEDIR%\x64

copy FrozenStorm\FrozenStorm.h %RELEASEDIR%\
copy FrozenStorm\FrozenStormWrapper.h %RELEASEDIR%\
copy bin\x32\FrozenStorm.dll %RELEASEDIR%\x32\
copy bin\x32\FrozenStorm.lib %RELEASEDIR%\FrozenStorm_x86.lib
copy bin\x64\FrozenStorm.dll %RELEASEDIR%\x64\
copy bin\x64\FrozenStorm.lib %RELEASEDIR%\FrozenStorm_x64.lib