/*
 * PBReading.hpp
 *
 *  Created on: 19-11-2010
 *      Author: mateusz
 */

#ifndef PBREADING_HPP_
#define PBREADING_HPP_

#include "Reading.hpp"
#include "Types/HomogMatrix.hpp"

namespace Types {
namespace Mrrocpp_Proxy {

/**
 *
 */
class PBReading: public Reading
{
public:
	PBReading() : objectVisible(false)
	{
	}

	virtual ~PBReading()
	{
	}

	virtual PBReading* clone()
	{
		return new PBReading(*this);
	}

	bool objectVisible;
	Types::HomogMatrix objectPosition;

	virtual void send(boost::shared_ptr<xdr_oarchive<> > & ar){
		*ar<<*this;
	}

private:
	friend class boost::serialization::access;
	template <class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
//		LOG(LWARNING) << "PBReading::serialize()\n";
		ar & boost::serialization::base_object <Reading>(*this);

		ar & objectVisible;
		ar & objectPosition;
	}
};

}//namespace Mrrocpp_Proxy
}//namespace Types

#endif /* PBREADING_HPP_ */
