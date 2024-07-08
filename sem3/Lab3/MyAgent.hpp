#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "MyAgent.generated.hpp"

namespace exampleModule
{
class MyAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::my_agent, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};
}
