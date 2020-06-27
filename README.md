# Document-monitoring
文件监控系统
使用C++语言，利用Visual studio软件来进行编写。
使用FileSystemWatcher控件， 
Changed  ：当更改文件和目录时发生，可以通过NotifyFilter属性设置触发该事件的需要文件更改的属性，
Created  ：  当创建文件和目录时发生，
Deleted ：删除文件或目录时发生 ，
Renamed  ：重命名文件或目录时发生。
建立FileSystemWatcher.h头文件，引入FileSystemWatcher控件，在FileSystemWatcher.cpp中详细设定线程函数等，最后创建主函数源.cpp，在其中写入监控文件夹地址及屏幕显示样式。
