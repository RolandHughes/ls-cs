REM astyle-project.bat
REM
forfiles /S /M *.cpp /C "astyle -n @FILE"
forfiles /S /M *.h /C "astyle -n @FILE"
