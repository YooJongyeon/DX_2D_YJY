#include "framework.h"
#include "ItemDataes.h"

ItemDataes::ItemDataes()
{
	_items.reserve(10);
}

ItemDataes::~ItemDataes()
{
}

void ItemDataes::InitData()
{
	string path = "Resource/XML/";
	string file = "ItemData.xml";
	tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument();
	document->LoadFile((path + file).c_str());

	tinyxml2::XMLElement* atlas = document->FirstChildElement("Workbook");
	tinyxml2::XMLElement* workSheet = atlas->FirstChildElement("Worksheet");
	tinyxml2::XMLElement* table = workSheet->FirstChildElement("Table");
	tinyxml2::XMLElement* row = table->FirstChildElement("Row");

	row = row->NextSiblingElement();

	while (row != nullptr)
	{
		tinyxml2::XMLElement* cell = row->FirstChildElement();
		tinyxml2::XMLElement* data = cell->FirstChildElement();

		ItemData itemData;
		itemData.name = data->GetText();
		//int value = 0;
		//int prive = 0;
		//int type = 0;
		//int attack = 0;
		//int defence = 0;

		//itemData.value = atoi(data->NextSiblingElement()->GetText());
	}


}
