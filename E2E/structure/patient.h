/*
 * Copyright (c) 2018 Kay Gawlik <kaydev@amarunet.de> <kay.gawlik@beuth-hochschule.de> <kay.gawlik@charite.de>
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#pragma once

#include "study.h"
#include "substructure_template.h"

namespace E2E
{
	class TextElement;
	class TextElement16;
	class PatientDataElement;
	class PatImage_2335;

	class Patient : public SubstructureTemplate<Study>
	{
		PatientDataElement* patientData = nullptr;
		TextElement*        patientUID  = nullptr;
		TextElement16*      diagnose    = nullptr;

		PatImage_2335*      patImageL   = nullptr;
		PatImage_2335*      patImageR   = nullptr;


		StringListElement*  ancestry    = nullptr;
	public:
		Patient(E2EData* parent) : SubstructureTemplate(parent) {}
	    virtual ~Patient();

		      Study& getStudy(int studyId)                      { return getAndInsert(studyId)         ; }
		const Study& getStudy(int studyId) const                { return *(substructureMap.at(studyId)); }

		std::size_t getSeriesSize() const                       { return substructureMap.size(); }

		PatientDataElement* getPatientData() const              { return patientData;     }
		void takePatientData(PatientDataElement* pat);
		
		TextElement* getPatientUID() const                      { return patientUID; }
		void takePatientUID(TextElement* uid);

		void takePatImage_2335(PatImage_2335* img);
		PatImage_2335* getPatImageR() const                     { return patImageR; }
		PatImage_2335* getPatImageL() const                     { return patImageL; }


		TextElement16* getDiagnose() const                        { return diagnose; }
		void takeDiagnose(TextElement16* diag);

		StringListElement* getAncestry() const                        { return ancestry; }
		void takeAncestry(StringListElement* anc);

	};


}

