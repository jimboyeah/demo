#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

//
// �йس��򼯵ĳ�����Ϣͨ���������Լ�
// ���ơ�������Щ����ֵ���޸�
// ����򼯹�������Ϣ��
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
// ���򼯵İ汾��Ϣ�������ĸ�ֵ���:
//
//      ���汾
//      �ΰ汾
//      ���ɺ�
//      �޶���
//
// ������ָ������ֵ��Ҳ��ʹ�á��޶��š��͡����ɺš���Ĭ��ֵ��
// �����ǰ�������ʾʹ�á�*��:

[assembly:AssemblyVersionAttribute("0.1.*")];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];

// warning C4947: ��System::Security::Permissions::SecurityAction::RequestMinimum��: ���Ϊ�ѹ�ʱ
// [assembly:SecurityPermission(SecurityAction::PermitOnly, UnmanagedCode = true)];
