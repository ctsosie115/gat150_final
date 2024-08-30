#pragma once
#include "../Core/Serializable.h"
#include <string>

//#define CLASS_DECLARAITON(class)\
//	static const char* GetTypeName() {return #class;}\
//	virtual void Read(const json_t& value);\
//	virtual void Write(json_t& value);

#define CLASS_DECLARATION(classname)							\
	static const char * GetTypeName() { return #classname; }	\
	virtual void Read(const json_t& value);						\
	virtual void Write(json_t& value);

#define FACTORY_REGISTER(classname) \
    class Register##classname \
    { \
    public: \
        Register##classname() \
        { \
            Factory::Instance().Register<classname>(#classname); \
        } \
    }; \
    static Register##classname register_instance; 

#define CLASS_PROTOTYPE(classname) \
	virtual std::unique_ptr<Object> Clone() \
	{\
		return std::make_unique<classname>(*this); \
	}

class Object : public Serializable
{
public:
	Object() = default;
	Object(const std::string& name) : name{name} {}

	virtual std::unique_ptr<Object> Clone() = 0;

	virtual void Initialize() = 0;
	virtual void Active() { active = true; }
	virtual void Deactivate() { active = true; }

public:
	std::string name;
	bool active{ false };


	// Inherited via Serializable
	void Read(const json_t& value) override;

	void Write(json_t& value) override;

};