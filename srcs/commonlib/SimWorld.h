/*
 * Modified by okamoto on 2011-03-31
 */

#ifndef SimWorld_h
#define SimWorld_h

#include <string>
#include <map>
#include <assert.h>

#include "Vector3d.h"
#include "systemdef.h"
#include "SimObjBase.h"

class SimGround;


class SimWorld
{
	typedef std::string S;
public:
	typedef std::map<S, SimObjBase*> M;

	typedef std::map<std::string, Vector3d> m_posMap;
private:
	S	m_name;
protected:
	M 	m_objs;
	SimGround *m_ground;
private:
	double	m_time;

protected:
	virtual void	free_();
public:
	SimWorld(const char *name_);
public:
	virtual ~SimWorld() { free_(); }
	
	const M & objs() const { return m_objs; }
	SimObjBase * getObj(const char *name)
	{
		M::iterator i = m_objs.find(name);
		if (i == m_objs.end()) { return 0; }
		return i->second;
	}

	void	setGround(SimGround *p) { m_ground = p; }
	
	SimObjBase * getObjById(SimObjBase::Id id);

	int getAllEntitiesDataSize();

	virtual double	time() const { return m_time; }

#ifndef EXEC_SIMULATION
	void time(double t) { m_time = t; }
#endif

	void push(SimObjBase *obj);
#ifdef IMPLEMENT_DRAWER 
	void draw(DrawContext &c);
#endif

	void dump();
};

#endif // SimWorld_h


