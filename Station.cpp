// Name:Enock lubega
// Seneca Student ID: 154192181
// Seneca email:elubega@myseneca.ca
// Date of completion:7/15/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Station.h"
#include "Utilities.h"


namespace sdds {
	size_t Station::id_generator = 0;
	size_t Station::m_widthField = 0;

	Station::Station(const std::string line)
	{
		Utilities util;
		size_t pos = 0u;
		bool isMore = true;

		m_itemName = util.extractToken(line, pos, isMore);
		m_serial = stoi(util.extractToken(line, pos, isMore));
		m_quantity = stoi(util.extractToken(line, pos, isMore));

		if (m_itemName.length() > m_widthField) {
			m_widthField = m_itemName.length();
			util.setFieldWidth(m_widthField);
		}

		m_desc = util.extractToken(line, pos, isMore);
		m_id = ++id_generator;
	}
	const std::string& Station::getItemName() const
	{
		return m_itemName;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_serial++;
	}
	size_t Station::getQuantity() const
	{
		return m_quantity;
	}
	void Station::updateQuantity()
	{
		if (getQuantity() > 0)
			--m_quantity;
	}
	void Station::display(std::ostream& os, bool full) const
	{
		if (full) {
			os << "[" << std::setfill('0') << std::right << std::setw(3) << m_id << "]" << " Item: " << std::left << std::setfill(' ');
			os << std::setw(m_widthField) << getItemName() << " [" << std::setfill('0');
			os << std::setw(6) << std::right << m_serial << "] " << "Quantity: " << std::left << std::setfill(' ');
			os << std::setw(m_widthField) << getQuantity() << " Description: " << m_desc;

		}
		else {

			os << "[" << std::setfill('0') << std::setw(3) << m_id << "]" << " Item: " << std::left << std::setfill(' ') << std::setw(m_widthField) << m_itemName
			   << " [" << std::setfill('0') << std::setw(6) << std::right << m_serial << "]";

		}
		os << std::endl;
	}
}