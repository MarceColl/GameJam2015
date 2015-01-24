#include "Object.h"
#include <SFML/Graphics.hpp>

Object::Object(const rapidjson::GenericValue<rapidjson::UTF8<> >* d)
{
    // POINTER HAXURS
    objectName = (*d)["nom"].GetString();
    objectSize = strncmp((*d)["size"].GetString(), "small", 5) == 0 ? SMALL : BIG;
    isContainer = (*d)["is_container"].GetBool();
    isMovable = (*d)["is_movable"].GetBool();

    // PARSE STATES
    const rapidjson::Value& states = (*d)["states"];
    for (rapidjson::Value::ConstValueIterator itr = states.Begin(); itr != states.End(); ++itr) {
        for (rapidjson::Value::ConstValueIterator itr2 = itr->Begin(); itr2 != itr->End(); ++itr2) {
            possibleStates.push_back((*itr2).GetString());
        }
    }
    
    // PARSE ACTIONS-OBJECT
    rapidjson::Value::ConstMemberIterator actions_object = (*d).FindMember("actions-object");
    if (actions_object != (*d).MemberEnd()) {
        for (rapidjson::Value::ConstValueIterator itr = (*actions_object).value.Begin(); itr != (*actions_object).value.End(); ++itr) {
            DoesInteract ds;

            rapidjson::Value::ConstMemberIterator cmi = (*itr).FindMember("name");
            rapidjson::Value::ConstMemberIterator continueFrom = cmi;

            if (cmi != (*itr).MemberEnd()) {
                ds.name = (*cmi).value.GetString();
            } else {
                std::cerr << "Object action without name!" << std::endl;
            }

            cmi = (*itr).FindMember("modifier");
            if (cmi != (*itr).MemberEnd()) {
                ds.objectModif = (*cmi).value.GetString();
                continueFrom = cmi;
            } else {
                ds.objectModif = "";
            }

            continueFrom++;

            for (rapidjson::Value::ConstMemberIterator itr2 = continueFrom; itr2 != itr->MemberEnd(); ++itr2) {
                if(!strncmp(itr2->name.GetString(), "otherwise", 9)) {
                    StateChange sc;
                    sc.initState = itr2->name.GetString();
                    sc.finalState = itr2->value.GetString();
                    ds.stateChanged.push_back(sc);
                }
            }

            addInteraction(ds);
        }
    }

    // PARSE ACTIONS-RECEIVED
    rapidjson::Value::ConstMemberIterator actions_received = (*d).FindMember("actions-received");
    if (actions_received != (*d).MemberEnd()) {
        for (rapidjson::Value::ConstValueIterator itr = (*actions_received).value.Begin(); itr != (*actions_received).value.End(); ++itr) {
            RecievesInteract rs;

            rapidjson::Value::ConstMemberIterator cmi = (*itr).FindMember("name");
            rapidjson::Value::ConstMemberIterator continueFrom = cmi;

            if (cmi != (*itr).MemberEnd()) {
                rs.name = (*cmi).value.GetString();
            } else {
                std::cerr << "Object action without name!" << std::endl;
            }

            continueFrom++;

            for (rapidjson::Value::ConstMemberIterator itr2 = continueFrom; itr2 != itr->MemberEnd(); ++itr2) {
                if(strncmp(itr2->name.GetString(), "otherwise", 9) != 0) {
                    StateChange sc;
                    sc.initState = itr2->name.GetString();
                    sc.finalState = itr2->value.GetString();
                    rs.canvisEstat.push_back(sc);
                }
            }

            addInteraction(rs);
        }
    }

    // PARSE EVALUATION VALUES
    rapidjson::Value::ConstMemberIterator evaluation = (*d).FindMember("evaluation");
    if (actions_received != (*d).MemberEnd()) {
        for (rapidjson::Value::ConstMemberIterator itr = (*evaluation).value.MemberBegin(); itr != (*evaluation).value.MemberEnd(); ++itr) {
            if (strncmp((*itr).name.GetString(), "multipliers", 11) != 0) {
                rapidjson::Value::ConstValueIterator cvi = (*itr).value.Begin();
                EvalValues ev;
                ev.murder = (*cvi).GetDouble(); cvi++;
                ev.suicide = (*cvi).GetDouble(); cvi++;
                ev.accident = (*cvi).GetDouble(); cvi++;
                ev.disappearance = (*cvi).GetDouble();

                evalValues.insert(std::pair<std::string, EvalValues>((*itr).name.GetString(), ev));
            } else {
                for (rapidjson::Value::ConstMemberIterator cmi = (*itr).value.MemberBegin(); cmi != (*itr).value.MemberEnd(); ++cmi) {
                    rapidjson::Value::ConstValueIterator cvi = (*cmi).value.Begin();
                    MultipliersValues mv;
                    mv.protagonistImplication = (*cvi).GetDouble(); cvi++;
                    mv.neighborImplication = (*cvi).GetDouble(); cvi++;
                    mv.suicide = (*cvi).GetDouble(); cvi++;
                    mv.accident = (*cvi).GetDouble(); cvi++;
                    mv.disappearance = (*cvi).GetDouble();

                    multipliersValues.insert(std::pair<std::string, MultipliersValues>((*cmi).name.GetString(), mv));
                }
            }
        }
    }
}

void Object::setPosition(sf::Vector2f pos) {
	position = pos;	
}
   
void Object::setLocationInObject(std::string obj) {
	inObject = true;
}

void Object::addInteraction(DoesInteract di) {
	interactionsAvailable.insert(std::pair<std::string, DoesInteract>(di.name, di));
}

void Object::addInteraction(RecievesInteract ri) {
	interactionsRecievable.insert(std::pair<std::string, RecievesInteract>(ri.name, ri));
}

bool Object::canInteractWithAction(std::string act) {
	return (interactionsRecievable.count(act) != 0);
}

void Object::applyInteraction(std::string action) {
    RecievesInteract act = interactionsRecievable[action];
	std::vector<StateChange> modificacions = act.canvisEstat;
	for (std::vector<StateChange>::iterator it = modificacions.begin(); it != modificacions.end(); ++it){
		std::string initS = it->initState;
		for (std::vector<std::string>::iterator iter = initStates.begin(); iter != initStates.end(); ++iter){
			if(*iter==initS){
				*iter=(it->finalState);
				break;
			}
		}
	}
}

