
# Project & Build Systems
- https://www.sublimetext.com/docs/3/projects.html
- https://sublime.wbond.net/packages/Project%20Manager
- http://sublime-text.readthedocs.org/en/latest/reference/build_systems.html

在旧版本 Sublime 可以使用 Project Manager 插件。按下 Ctrl-Shift-P 输入命令 Project Manager，简写 PM，列出所有工程管理命令，选择 Add New Project 将当前打开的目录保存到工程中进行管理，已在管理的工程只可以通过 `Ctrl+Alt+P` 切换。

在但在新版本中，不必安装插件了，配置快捷键就可以。本机版本是 3210，快速切换的快键键 Ctrl+Alt+P 已不在默认设置中，因此没效果，这时可以添加到自定义 keymap，菜单 Preference -> Key Bindings，添加如下:

    {
        "keys": ["ctrl+alt+p"],
        "command": "prompt_select_workspace"
    }

如果，没效果，可能是快捷键有冲突。

Sublime 的 Build Systems 是很强大很灵活的，可以为指定的文件上下文，Ctrl-Shift-Alt-P 查看，配置命令，将命令配置保存在 `.build-system` 文件中即可以调用，Ctrl-B 或 Ctrl-Shift-B 调用。

内置的 Build Systems 默认就有 Node.js 的编译命令，安装 Node.js 就可以使用，Tools -> Build Systems -> Node.js，或者在打开 JS 文件的状态下按 Ctrl-B 调用。

创建自定义 Build 命令工具，执行菜单 Tools -> Build System -> New Build System ... 会自动创建一个 `.build-system` 文件，编辑好后保存到 Packages/User 目录下即可。

构建系统的命令配置也可以在 Sublime Text 的工程文件中，配置构建命令如下 demo.sublime-project，注意 working_dir 设置的当前工作目录一定要存在，否则命令不能执行，${project_path} 表示工程文件所在目录：

    {
        "build_systems":
        [
            {
                "name": "MyProject (Windows)",
                "file_regex": "^  (.+)\\((\\d+)\\)(): ((?:fatal )?(?:error|warning) \\w+\\d\\d\\d\\d: .*) \\[.*$",
                "shell_cmd": "cmake --build .",
                "syntax": "Packages/Users/CMake.sublime-syntax",
                "encoding":"gbk",
                "quiet": true,
                "variants":
                [
                    {"name": "Test", "shell_cmd":"echo Testing..."},
                    {
                        "name": "Unix Makefiles",
                        "shell_cmd": "cmake .. -G 'Unix Makefiles'"
                    },
                    {
                        "name": "clean",
                        "shell_cmd": "make clean"
                    },
                    {
                        "name": "clear all",
                        "shell_cmd": "del * /q"
                    },
                    {
                        "name": "Make",
                        "shell_cmd": "make"
                    }
                ],
                "working_dir": "${project_path}/build"
            }
        ],
        "folders":
        [
            {
                "path": "."
            }
        ],
        "settings":
        {
            "cmake":
            {
                "build_folder": "${project_path}/build"
            }
        }
    }

参数解析：

- `name` 命令配置名称，同名配置会覆盖前面的配置。

- `cmd` 和 `shell_cmd` 执行命令两种设置方式，但对于 `variants` 命令变体设置中，只能使用 shell_cmd 方式：

        "cmd": ["cmake", ".", "-g", "Sublime Text 2 - Ninja"],
        "shell_cmd": "cmake .. -G \"Sublime Text 2 - Ninja\"",

    shell_cmd 方式指定一个字符串执行，cmd 方式指定一个列表，其第一项为命令或可执行程序，其它后续的为参数，会自动添加引号到命令行。

- `file_regex` 用来处理输出信息指定的定位内容，如php脚本运行输出提示信息，其中文件名/行号可以提取，点击这条信息就可以定位到代码

        PHP Notice:  Use of undefined constant b - assumed 'b' in E:\coding\coding.php on line 49

- `selector` 是 sublime 用来自动关联当前编辑文件与 build 工具的关键字，可以通过菜单获取：

        Tools => Developer => Show Scope Name

    获取当前光标位置所在的作用域，拷贝下来后用来配置 build 工具。

- `quiet` 是静默模式配置，如果设置 true 打开靓车模式，在执行命令出错时就不会输出环境变量信息。

- `syntax` 文件语法格式配置。

- `encoding` 命令行输出内容的编码，一般中文操作系统指定 "gbk" 或者 "utf8"。

- `variants` 命令变体，可以设置多个不同参数的命令执行方式，只能使用 shell_cmd 不能使用 cmd。


编译命令还可以扩展 sublime.WindowCommand 接口实现。


目录还可以进行细致的配置：

    {
        "folders":
        [
            {
                "path": "src",
                "folder_exclude_patterns": ["backup"],
                "follow_symlinks": true
            },
            {
                "path": "docs",
                "name": "Documentation",
                "file_exclude_patterns": ["*.css"]
            }
        ],
        "settings":
        {
            "tab_size": 8
        },
        "build_systems":
        [
            {
                "name": "List",
                "shell_cmd": "ls -l"
            }
        ]
    }

FOLDERS 配置，path 是必须的，路径可以是绝对或相对的，此外还可以配置：

- `name` - 在 sidebar 显示的名字。
- `file_include_patterns` - 文件名匹配列表，匹配的文件才显示。
- `file_exclude_patterns` - 文件名匹配列表，匹配的文件不显示。
- `folder_include_patterns` - 目录匹配列表，匹配的文件才显示。
- `folder_exclude_patterns` - 目录匹配列表，匹配的文件不显示。
- `binary_file_patterns` - 二进制文件匹配列表，匹配的文件不执行查找、符号定位，节省资源提高效率。
- `index_include_patterns` - 索引目录匹配列表，对匹配的目录进行索引。
- `index_exclude_patterns` - 索引目录匹配列表，不对匹配的目录进行索引。
- `follow_symlinks` - If symlinks should be followed when building the folder tree.


## 内置变量
http://www.sublimetext.com/docs/3/build_systems.html#variables

    $packages           The path to the Packages/ folder
    $platform           A string containing the platform Sublime Text is running on: windows, osx or linux.
    $file               The full path, including folder, to the file in the active view.
    $file_path          The path to the folder that contains the file in the active view.
    $file_name          The file name (sans folder path) of the file in the active view.
    $file_base_name     The file name, exluding the extension, of the file in the active view.
    $file_extension     The extension of the file name of the file in the active view.
    $folder             The full path to the first folder open in the side bar.
    $project            The full path to the current project file.
    $project_path       The path to the folder containing the current project file.
    $project_name       The file name (sans folder path) of the current project file.
    $project_base_name  The file name, excluding the extension, of the current project file.
    $project_extension  The extension of the current project file.

## 可配置项

exec Target Options

    cmd: ["my_command", "-d", "$file"]

A list of strings specifying the executable to run, plus any arguments to pass to it. Shell constructs such as piping and redirection are not supported – see shell_cmd. May use variables.

    shell_cmd: "my_command \"$file\" | other_command"

A string specifying a shell command to execute. Unlike the cmd option, this does allow piping and redirection. Will use bash on Mac and Linux machine, and cmd.exe on Windows. May use variables.

    working_dir: "$file_path"

A string specifying the directory to execute the cmd or shell_cmd within. May use variables.

    file_regex: "^\s*(\\S[^:]*)\\((\\d+):(\\d+)\\): ([^\\n]+)"

A string containing a regular expression to run on the build output to match file information. The matched file information is used to enable result navigation. The regex should capture 2, 3 or 4 groups.

The capture groups should be: filename, line number, column number and message

    line_regex: "^\s*line (\\d+) col (\\d+): ([^\\n]+)"

A string containing a regular expression to run on the build output to match line information. The matched file information is used to enable result navigation. The regex should capture 1, 2 or 3 groups.

The groups should capture: line number, column number, error message.

This regular expression is only necessary when some results contain strictly a line number, line and column numbers, or line and column numbers with a message. When such a match is made, the file_regex option will be used to search backwards to find the appropriate file name. 

    encoding: "iso-8859-1"

A string specifying the encoding of the build system output. Uses Python codec names. Defaults to "utf-8".

    env: {"PYTHONIOENCODING": "utf-8"}
    
An object containing environment variable values to use when running the cmd or shell_cmd.

    quiet: true

A boolean that reduces the amount of output about the build system invocation.

    word_wrap: true

A boolean that turns on word wrapping in the build system output panel.

    syntax: "Packages/JavaScript/JSON.sublime-syntax"

A string specifying the syntax file to use to highlight the build system output panel.


## Custom Options

When implementing a command to act as a build system target, the command's keyword arguments are available via options in the .sublime-build file. However, certain parameter names will not work since they conflict with built-in build system functionality.

The following names will not be passed as arguments to commands. This also applies to other situations, such as options specified in the cancel, linux, osx and windows options.

    cancel
    file_patterns
    keyfile
    keyfiles
    linux
    osx
    save_untitled_files
    selector
    target
    variants
    windows


## SQLExec

Git Clone代码到本地:

    git clone http://www.github.com/jum4/sublime-sqlexec

Subversion代码到本地:

    $ svn co --depth empty http://www.github.com/jum4/sublime-sqlexec
    Checked out revision 1.
    $ cd repo
    $ svn up trunk

在 Sublime 文本中运行SQL命令的插件。

    Features
    ctrl+alt+e         Switching between connections
    ctrl+e ctrl+d      Desc table
    ctrl+e ctrl+s      Quick show table records
    ctrl+e ctrl+q      Execute queries
    ctrl+e ctrl+e      Execute selected query and show the result un the output panel.
    ctrl+e ctrl+h      Show an quick pane containing the history of queries

    Installation
    With Package Control
    Look for the package named SQLExec.

    With Git
    Download the Zip file, extract it to your Sublime Text packages directory, and rename it to SQLExec.

    Requirements
    Some directories have to be defined in the PATH environment variable, according to the SGBD that you want to use: "mysql" executable for MySQL, "pgsql" executable for PostgreSQL, "vsql" executable for Vertica, or "sqlplus" executable for Oracle ( Not tested ).

    You can also specify full path for these command in settings :

    ( Preferences > Package Settings > SQLExec > Settings - User )

        "sql_exec.commands": {
            "mysql" : "/usr/bin/mysql"
        },

    Configuration
    Sample configuration file
    The configuration file is accessible by the menu
    ( Preferences > Package Settings > SQLExec > Settings - User )

        {
             "connections": {
                 "Connection 1": {
                     "type"    : "mysql",
                     "host"    : "127.0.0.1",
                     "port"    : 3306,
                     "username": "user",
                     "password": "password",
                     "database": "dbname"
                 },
                 "Connection 2": {
                     "type"    : "pgsql",
                     "host"    : "127.0.0.1",
                     "port"    :  5432,
                     "username": "anotheruser",
                     "database": "dbname"
                 },
                 "Connection 2": {
                     "type"    : "oracle",
                     "host"    : "127.0.0.1",
                     "port"    :  1522,
                     "username": "anotheruser",
                     "password": "password",
                     "database": "dbname",
                     "service" : "servicename"
                 }
             }
         }

    Options
    show_result_on_window (default:false)
    By default, query results are displayed in the quick panel. By setting this param to true, you can specify that all results will be displayed in a separate window instead.




## Node.js ES6

`-harmony` 选项打开 node 的 ES6 特性支持，要运行 TypeScript 需要先安装解释器，一并安装 ts-node 这个直接运行 TypeScript 程序的工具。

    {
        "cmd": ["node", "--harmony", "$file"],
        "file_regex": "^[ ]* at .* \\((.*?):([0-9]*):([0-9]*)\\)",
        "selector": "source.js, source.ts",
        "shell": true,
        "encoding": "utf-8",
        "variants": [{
            "name": "TypeScript[ts-node]",
            "shell_cmd": "ts-node $file"
        }, {
            "name": "TypeScript ES3)",
            "shell_cmd": "tsc $file"
        }, {
            "name": "TypeScript ES5)",
            "shell_cmd": "tsc -t ES5 $file"
        }, {
            "name": "TypeScript ES6)",
            "shell_cmd": "tsc -t ES6 $file"
        }, {
            "name": "ES6(ECMAScript 2015)",
            "shell_cmd": "node --harmony $file"
        }, {
            "name": "ES5(ECMAScript 2009)",
            "shell_cmd": "node $file"
        }],
        // "windows": {
        //     "shell_cmd": "node $file", // echo try to Kill node.exe & taskkill /F /IM node.exe & 
        // },
        "linux": {
            "shell_cmd": "killall node; /usr/bin/env node $file"
        },
        "osx": {
            "shell_cmd": "killall node; /usr/bin/env node $file"
        }
    }

## julia

    {
        "shell_cmd": "C:/Julia-1.0.0/bin/julia.exe \"$file\"",
        // "cmd": ["C:/Julia-1.0.0/bin/julia.exe", "${file}"],
        "working_dir": "${file_path}",
        "path":"C:/Julia-1.0.0/bin/",
        "file_regex": "^[ ]*File \"(...*?)\", line ([0-9]*)",
        "selector": "source.julia"
    }

## php

    {
        "cmd": ["php.exe", "-f", "${file}"],
        "working_dir": "${file_path}",
        "path":"c:/php7.1.16",
        "file_regex": "^.* in (.*?) on line ([0-9]*)",
        "selector": "embedding.php, source.php"
    }

## JAVA

    {
        // "shell_cmd": "javac.exe \"$file\" && java.exe \"$file_base_name\"",
        // "shell_cmd": "ECHO Compiling $file_base_name.java & javac -encoding UTF-8 \"$file\" & java \"$file_base_name\"",
        "shell_cmd": "ECHO Compiling $file_base_name.java && javac -encoding UTF-8 \"$file\" && java \"$file_base_name\"",
        "file_regex": "^(...*?):([0-9]*):?([0-9]*)",
        "working_dir": "${file_path}",
        "selector": "source.java",
        "encoding":"gbk",
        "variants":[
             {   
                "name":"编译",
                "shell_cmd": "ECHO Compiling $file_base_name.java & javac -d . -encoding UTF-8 \"$file\"",
            },
            {   
                "name":"运行当前类",
                "shell_cmd":" java \"$file_base_name\" "       
            },
            {   
                "name":"cmd中运行",
                "shell_cmd":" start cmd /c \"javac -encoding UTF-8 \"$file\" & java \"$file_base_name\" & pause \""  
            }
       ]
    }


## MinGW GCC

    {
        // "cmd": ["E:\CodeBlocks\MinGW\bin\gcc.exe", "$file"],
        "env": {
            "QTDIR":"C:/Qt/5.9/mingw53_32",
            "PATH":"C:/Qt/5.9/mingw53_32/bin;C:/Qt/Tools/mingw530_32/bin;%PATH%",
            "inc":"-IC:/Qt/5.9/mingw53_32/include -IC:/Qt/5.9/mingw53_32/include/QtCore -IC:/Qt/5.9/mingw53_32/include/QtGui -IC:/Qt/5.9/mingw53_32/include/QtQuick -IC:/Qt/5.9/mingw53_32/include/QtQml -IC:/Qt/5.9/mingw53_32/include/QtWidgets",
            "libpath":"-LC:/Qt/5.9/mingw53_32/lib",
            "libs":"-lQt5Core -lQt5Gui -lQt5Widgets -lQt53DAnimation -lQt53DCore -lQt53DExtras -lQt53DInput -lQt53DLogic -lQt53DQuick -lQt53DQuickAnimation -lQt53DQuickExtras -lQt53DQuickInput -lQt53DQuickRender -lQt53DQuickScene2D -lQt53DRender -lQt5AccessibilitySupport -lQt5AxBase -lQt5AxContainer -lQt5AxServer -lQt5Bluetooth -lQt5Bootstrap -lQt5Charts -lQt5Concurrent -lQt5DataVisualization -lQt5DBus -lQt5Designer -lQt5DesignerComponents -lQt5DeviceDiscoverySupport -lQt5DeviceDiscoverySupport -lQt5EglSupport -lQt5EventDispatcherSupport -lQt5EventDispatcherSupport -lQt5FbSupport -lQt5FontDatabaseSupport -lQt5Help -lQt5Location -lQt5Multimedia -lQt5MultimediaQuick_p -lQt5MultimediaWidgets -lQt5Network -lQt5NetworkAuth -lQt5Nfc -lQt5OpenGL -lQt5OpenGLExtensions -lQt5PacketProtocol -lQt5Positioning -lQt5PrintSupport -lQt5Purchasing -lQt5Qml -lQt5QmlDebug -lQt5QmlDevTools -lQt5Quick -lQt5QuickControls2 -lQt5QuickParticles -lQt5QuickTemplates2 -lQt5QuickTest -lQt5QuickWidgets -lQt5RemoteObjects -lQt5Script -lQt5ScriptTools -lQt5Scxml -lQt5Sensors -lQt5SerialBus -lQt5SerialPort -lQt5Sql -lQt5Svg -lQt5Test -lQt5TextToSpeech -lQt5ThemeSupport -lQt5UiTools -lQt5WebChannel -lQt5WebSockets -lQt5WinExtras -lQt5Xml -lQt5XmlPatterns -lqtfreetype -lqtlibpng -lqtmain ",
            "cc":"g++.exe -Wall -Wno-unused-variable"
        },
        "env": {
            "PATH":"C:/CodeBlocks/MinGW/bin;C:/download/OpenCV/MinGW-OpenCV-4.1.1-x64/x64/mingw/bin;%PATH%",
            "inc":"-IC:/download/OpenCV/MinGW-OpenCV-4.1.1-x64/include -IC:/download/OpenCV/MinGW-OpenCV-4.1.1-x64/include/opencv2",
            "libpath":"-LC:/download/OpenCV/MinGW-OpenCV-4.1.1-x64/x64/mingw/lib",
            "libs":"-lopencv_calib3d411 -lopencv_core411 -lopencv_dnn411 -lopencv_features2d411 -lopencv_flann411 -lopencv_gapi411 -lopencv_highgui411 -lopencv_imgcodecs411 -lopencv_imgproc411 -lopencv_ml411 -lopencv_objdetect411 -lopencv_photo411 -lopencv_stitching411 -lopencv_video411 -lopencv_videoio411",
            "cc":"g++.exe -Wall -Wno-unused-variable"
        },
        "shell_cmd": "ECHO MinGW GCC 8.1.0 Compiling $file_name ... && %cc% -g -std=c++11 %inc% -c \"$file\" -o $file_base_name.o && g++.exe %libpath% -o ${file_base_name}.exe ${file_base_name}.o %libs% && echo done.",
        "file_regex": "^(...*?):([0-9]*):?([0-9]*)",
        "working_dir": "${file_path}",
        "selector": "source.c++",
        "encoding":"utf8",
        "quiet": true,
        "variants":[
            {
                "name":"(-std=c++17)",
                "shell_cmd":"ECHO Compiling (-std=c++17) $file_name ... && %cc% -g -std=c++17 -c \"$file\" -o $file_base_name.o && g++.exe -o ${file_base_name}.exe ${file_base_name}.o && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-std=c++14)",
                "shell_cmd":"ECHO Compiling (-std=c++14) $file_name ... && %cc% -g -std=c++14 -c \"$file\" -o $file_base_name.o && g++.exe -o ${file_base_name}.exe ${file_base_name}.o && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-std=c++11)",
                "shell_cmd":"ECHO Compiling (-std=c++11) $file_name ... && %cc% -g -std=c++11 -c \"$file\" -o $file_base_name.o && g++.exe -o ${file_base_name}.exe ${file_base_name}.o && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-std=c++11) with ENV",
                "shell_cmd":"ECHO Compiling (-std=c++11) $file_name ... && %cc% -g -std=c++11 %inc% -c \"$file\" -o $file_base_name.o && g++.exe %libpath% -o ${file_base_name}.exe ${file_base_name}.o %libs% && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-std=c++11) Release with ENV",
                "shell_cmd":"ECHO Compiling (-std=c++11) $file_name ... && %cc% -DNDEBUG -std=c++11 %inc% -c \"$file\" -o $file_base_name.o && g++.exe %libpath% -o ${file_base_name}.exe ${file_base_name}.o %libs% && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-std=c++0x) with ENV",
                "shell_cmd":"ECHO Compiling (-std=c++0x) $file_name ... && %cc% -g -std=c++0x %inc% -c \"$file\" -o $file_base_name.o && g++.exe %libpath% -o ${file_base_name}.exe ${file_base_name}.o %libs% && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-std=c++98) with ENV",
                "shell_cmd":"ECHO Compiling (-std=c++98 $file_name ... && %cc% -g -std=c++98 %inc% -c \"$file\" -o $file_base_name.o && g++.exe %libpath% -o ${file_base_name}.exe ${file_base_name}.o %libs% && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-ansi) with ENV",
                "shell_cmd":"ECHO Compiling (-ansi) $file_name ... && %cc% -g -ansi %inc% -c \"$file\" -o $file_base_name.o && g++.exe %libpath% -o ${file_base_name}.exe ${file_base_name}.o %libs% && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-std=c11) with ENV",
                "shell_cmd":"ECHO Compiling (-std=c11) $file_name ... && %cc% -g -std=c11 %inc% -c \"$file\" -o $file_base_name.o && g++.exe %libpath% -o ${file_base_name}.exe ${file_base_name}.o %libs% && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-std=c99) with ENV",
                "shell_cmd":"ECHO Compiling (-std=c99) $file_name ... && g++.exe -Wall -g -std=c99 %inc% -c \"$file\" -o $file_base_name.o && g++.exe %libpath% -o ${file_base_name}.exe ${file_base_name}.o %libs% && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"(-std=c90) with ENV",
                "shell_cmd":"ECHO Compiling (-std=c90) $file_name ... && g++.exe -Wall -g -std=c90 %inc% -c \"$file\" -o $file_base_name.o && g++.exe %libpath% -o ${file_base_name}.exe ${file_base_name}.o %libs% && ECHO Start run $file_name ... && ${file_base_name} "
            },
            {
                "name":"控制台中运行",
                "shell_cmd":"start cmd /c \"${file_base_name} & pause \""  
            }
        ]
    }



## C++

    {
        "working_dir": "$file_path",
        "cmd": "g++ -Wall -std=c++14 -fexec-charset=GBK \"$file_name\" -o \"$file_base_name\"",
        "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
        "selector": "source.c, source.cpp",
     
        "variants": 
        [
            {   
                "name": "Run",
                "shell_cmd": "g++ -Wall -std=c++11 -fexec-charset=GBK \"$file\" -o \"$file_base_name\" && start cmd /c \"\"${file_path}/${file_base_name}\" & pause\""
            }
        ]
    }


## C# C-Sharp

首先安装 .Net Core 或 .Net Framework，再配置你的 Sublime 编译工具，将 Sublime 项目保存到 DotNet 项目中，可以使用 $project_path 引用。因为 .Net Core 支持中文输出，在中文系统中指定 "encoding": "cp936" 防止控制台乱码：

    {
        "env": {
            "PATH":"C:\\Program Files (x86)\\MSBuild\\14.0\\Bin;C:\\Windows\\Microsoft.NET\\Framework\\v4.0.30319\\;%PATH%",
            "libs":"/lib:./bin/ /r:a.dll,b.dll,c.dll",
        },
        "working_dir": "$file_path",
        "cmd": "csc.exe $file",
        "file_regex": "^(.[^\\(]*)\\(([0-9]+),([0-9]+)\\):(.*)$",
        "selector": "source.cs, text.xml, source.csproj, source.fsharp",
        "encoding": "cp936",
        "quiet": true,
        "variants": [{
            "name": "Build Exe & Run ...",
            "shell_cmd": "csc.exe $file_name && $file_base_name"
        },{
            "name": "Build DLL",
            "shell_cmd": "csc.exe /target:library $file"
        },{
            "name": "Run",
            "shell_cmd": "$file_base_name"
        },{
            "name": ".Net New",
            "shell_cmd": "dotnet new console -o demo"
        },{
            "name": ".Net Run",
            "shell_cmd": "dotnet run"
        },{
            "name": ".Net Watch",
            "shell_cmd": "dotnet watch run"
        },{
            "name": ".Net Run Project",
            "shell_cmd": "echo $project_path && dotnet run --project $project_path"
        },{
            "name": ".Net Watch Project",
            "shell_cmd": "echo $project_path && dotnet watch run --project $project_path"
        },{
            "name": "Run with Test Arguments",
            "shell_cmd": "$file_base_name http://baidu.com/ http://golang.org/ http://goproxy.io"
        }]
    }   


## Nim Language

    {
        "cmd": ["c:\\C:\nim-1.0.0\\bin\\nim.exe", "run", "${file}"],
        "env": {
            "PATH":"C:/nim-1.0.0/bin;c:\\CodeBlocks\\MinGW\\bin\\;%PATH%",
        },
        "working_dir": "${file_path}",
        "PATH":"C:/nim-1.0.0/bin;%PATH%",
        "file_regex": "^(.+\\.nim)\\(([0-9]*), ([0-9]+)\\) (.+)",
        "selector": "source.nim",
        "variants": [{
            "name": "nim build",
            "shell_cmd": "nim.exe c $file"
        },{
            "name": "run",
            "shell_cmd": "$file_base_name"
        },{
            "name": "run with Test Arguments",
            "shell_cmd": "$file_base_name http://baidu.com/ http://golang.org/ http://goproxy.io"
        }]
    }   


## Golang

可以使用 margo/GoSublime 插件
https://github.com/DisposaBoy/GoSublime

    {
        "cmd": ["c:\\go\\bin\\go.exe", "run", "${file}"],
        "env": {
            "PATH":"c:/go/bin;c:\\CodeBlocks\\MinGW\\bin\\;%PATH%",
        },
        "working_dir": "${file_path}",
        "PATH":"c:/go/bin;%PATH%",
        "file_regex": "^(.+\\.go):([0-9]*):([0-9]+):(.+)",
        "selector": "source.go",
        "variants": [{
            "name": "Go build",
            "shell_cmd": "go build -ldflags=\"-s -w\" $file"
        },{
            "name": "Go build Window GUI App",
            "shell_cmd": "go build -ldflags=\"-H windowsgui -s -w\" $file"
        },{
            "name": "Go Release Window GUI App",
            "shell_cmd": "go build -ldflags=\"-H windowsgui -s -w\" $file && upx $file_base_name.exe"
        },{
            "name": "Go Release App",
            "shell_cmd": "go build -ldflags=\"-s -w\" $file && upx $file_base_name.exe"
        },{
            "name": "Go run",
            "shell_cmd": "go build -ldflags=\"-s -w\" $file && $file_base_name"
        },{
            "name": "Go install",
            "shell_cmd": "go install $file"
        },{
            "name": "Go run with Test Arguments",
            "shell_cmd": "go run $file http://baidu.com/ http://golang.org/ http://goproxy.io"
        }]
    }   



## python

    {
        "encoding": "utf-8",
        "working_dir": "$file_path",
        "shell_cmd": "python -u \"$file\"",
        "file_regex": "^[ ]*File \"(...*?)\", line ([0-9]*)",
        "selector": "source.python",
     
        "variants":
        [
            {
                "name": "Run",
                "shell_cmd": "start cmd /c \"python -u \"$file\" & pause\"",
            }
        ]
    }

## windows 脚本宿主

通过 cscript.exe 和 wscript.exe 运行 VBS 或 JScript 脚本，c/w 分别表示运行环境 Console/Window

    {
        "cmd":["cscript.exe", "$file"],
        "file_regex": "^[ ]*File \"(...*?)\", line ([0-9]*)",
        "selector": "source.js, source.wsj"
    }

