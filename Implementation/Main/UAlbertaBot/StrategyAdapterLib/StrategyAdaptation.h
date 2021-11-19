#pragma once

#include <vector>
#include <string>
// ========================= DEFINITIONS ========================== //

namespace Helpers
{
		enum class AdapterType
		{
			Rule_Based,
			Utlity_Based,
			Evolutionary_Based,
			DRL_Based
		};

		struct ProtossState 
		{
			int numZealots;          
			int numPylons;        
			int numDragoons;         
			int numProbes;           
			int numNexusCompleted;  
			int numNexusAll;         
			int numCyber;            
			int numCannon;          
			int numScout;           
			int numReaver;           
			int numDarkTeplar;
		};
}

namespace StrategyContexts
{
#pragma region Base Strategy Context

template <class TConcreteAdapter, class URaceState>
class StrategyContext 
{
public:
	StrategyContext();
	virtual ~StrategyContext() = default;

	std::string GetAdaptedStrategy(URaceState a_gstate);
	TConcreteAdapter GetAdapter() const;

protected:
	Helpers::AdapterType m_type;
	TConcreteAdapter<URaceState> m_adapter;
};

#pragma endregion


namespace StrategyAdapters
{
	#pragma region IAdapter

	template<class TRaceState>
	class IAdapter 
	{
		typedef std::pair<std::string, float> AdapationResult;
	public:
		IAdapter() = default;
		virtual ~IAdapter() = default;
		std::vector<AdapationResult> virtual GetAdaptationResults(TRaceState a_gstate) = 0;
	};

	#pragma endregion

	#pragma region Rule-based Adapter

	template<class TRaceState>
	class RuleBasedAdapter : public IAdapter <TRaceState>
	{

	};

	#pragma endregion

	class UtilityBasedAdapter {};
	class EvolutionaryBasedAdapter {};
	class DRLBasedAdapter {};
}

namespace RuleBasedImplementation 
{
	class State{};
	class StateMachine{};
	class StateTransition{};
}

namespace UtilityBasedImplementation
{
	class UtilityStateTransition : public RuleBasedImplementation::StateTransition {};
	class UtilityScorer{};
}

namespace EvolutionaryBasedImplementation
{
}

namespace DRLBasedImplementation
{
}


// ========================= IMPLEMENTATIONS ========================== //

#ifdef STRGY_ADPT_IMPLEMENTATION_H

#endif