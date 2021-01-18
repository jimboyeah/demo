#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

//
// 有关程序集的常规信息通过下列特性集
// 控制。更改这些特性值可修改
// 与程序集关联的信息。
//
[assembly:AssemblyTitleAttribute(".NET CLR Application with Resource")];
[assembly:AssemblyDescriptionAttribute(".NET CLR Application with Resource")];
[assembly:AssemblyConfigurationAttribute("")];
[assembly:AssemblyCompanyAttribute("Microsoft")];
[assembly:AssemblyProductAttribute("CLRC")];
[assembly:AssemblyCopyrightAttribute("Copyright (c) Microsoft 2013")];
[assembly:AssemblyTrademarkAttribute("")];
// [assembly:AssemblyCultureAttribute("zh-CN")];

//
// 程序集的版本信息由下面四个值组成:
//
//      主版本
//      次版本
//      生成号
//      修订号
//
// 您可以指定所有值，也可使用“修订号”和“生成号”的默认值，
// 方法是按如下所示使用“*”:

[assembly:AssemblyVersionAttribute("0.1.*")];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];

// warning C4947: “System::Security::Permissions::SecurityAction::RequestMinimum”: 标记为已过时
// [assembly:SecurityPermission(SecurityAction::PermitOnly, UnmanagedCode = true)];
