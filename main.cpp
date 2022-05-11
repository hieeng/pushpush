#include <iostream>
#include "controller.h"

int main() {
	controller controller;

	while (controller.startMain() != 0);

	return 0;
}