#pragma once

/*
	This file is part of Kraft der Mada.
	Copyright (c) 2009 Daniel Wickert

    Kraft der Mada is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Kraft der Mada is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kraft der Mada. If not, see <http://www.gnu.org/licenses/>.
*/

#include "physics/PhysicsEntity.h"

namespace mada
{
	class PhysicsWorld : public RefCounted
	{
		__mada_declare_class(PhysicsWorld);
		__mada_declare_singleton(PhysicsWorld);
	public:
		PhysicsWorld();
		~PhysicsWorld();

		void open();
		void close();
		bool isOpen() const;

		void step(Time time);

		void attachEntity(Ptr<PhysicsEntity> entity);
		void detachEntity(Ptr<PhysicsEntity> entity);
		void clear();

	private:
		bool m_isOpen;

		///\todo use more suitable container like a quadtree.
		std::set<Ptr<PhysicsEntity> > m_entities;
	};
}
