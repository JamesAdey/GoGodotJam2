#include <Godot.hpp>
#include <Node.hpp>

namespace godot{
class Base : public godot::Node
{
	GODOT_CLASS(Base, godot::Node);

public:

	static void _register_methods()
	{
		register_method("_ready", &Base::_ready);
		register_method("test", &Base::test);
	}

	void _init(){}

	void _ready()
	{
		// Try to do something with this object. Will most likely crash because this object is garbage
		get_child_count(); 
        Godot::print("base ready");
	}

	void test()
	{
		// Will also crash if we get here
		get_child_count(); 
	}

	// You can uncomment this line to magically fix the crash
	//virtual void dummy() {}
};

class Derived : public Base
{
	GODOT_CLASS(Derived, Base);

public:

	static void _register_methods() {}
	void _init() {}

	// Commenting out this line would also fix the crashes in Base
	virtual void dummy() {}
};

}