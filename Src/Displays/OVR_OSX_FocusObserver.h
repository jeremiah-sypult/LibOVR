/************************************************************************************

Filename    :   OVR_OSX_FocusObserver.h
Content     :   Observer for app focus on OSX
Created     :   August 5, 2014
Authors     :   Jordan Tritell

Copyright   :   Copyright 2014 Oculus VR, LLC All Rights reserved.

Licensed under the Oculus VR Rift SDK License Version 3.2 (the "License");
you may not use the Oculus VR Rift SDK except in compliance with the License,
which is provided at the time of installation or download, or which
otherwise accompanies this software in either electronic or hard copy form.

You may obtain a copy of the License at

http://www.oculusvr.com/licenses/LICENSE-3.2

Unless required by applicable law or agreed to in writing, the Oculus VR SDK
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*************************************************************************************/

OVR_PRIVATE_FILE

#ifndef OVR_OSX_FocusObserver_h
#define OVR_OSX_FocusObserver_h

#include "../Kernel/OVR_Threads.h"
#include "../Kernel/OVR_System.h"
#include "../Kernel/OVR_Lockless.h"

#include "../Service/Service_NetServer.h"

namespace OVR { namespace OSX{

    struct FocusNotifierImpl;
    
class AppFocusObserver : public SystemSingletonBase<AppFocusObserver>    
{
    OVR_DECLARE_SINGLETON(AppFocusObserver);
    
public:
    Lock ListLock;
    Array<pid_t> AppList;
    Service::NetServerListener *listener;
    FocusNotifierImpl* impl;
    
    void OnProcessFocus(pid_t pid);
    void SetListener(Service::NetServerListener *_listener);
    
    pid_t LastProcessId;
    pid_t ActiveProcessId;
    void AddProcess(pid_t pid);
    void nextProcess();
    void RemoveProcess(pid_t pid);
    
    
protected:
    void onAppFocus(pid_t pid);
    
    pid_t LastAppFocus;
    
};
    
    
 
}} // namespace OVR, OSX


#endif /* OVR_OSX_FocusObserver_h */

