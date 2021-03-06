#include "_hooks.hpp"



void dKeyboardJoystick_Update(KeyboardJoystick* __this, MethodInfo* method) {
	if (IsInGame()) {
		if (!State.rpcQueue.empty()) {
			auto rpc = State.rpcQueue.front();
			State.rpcQueue.pop();

			rpc->Process();
			delete rpc;
		}
	}
	if (!State.FreeCam) {
		app::KeyboardJoystick_Update(__this, method);
	}
}