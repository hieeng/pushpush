#include "controller.h"
int controller::startMain() {
	_view._data.copy();
	while (_view.showStartScreen() != 0);
	return 0;
}
