#ifndef INFLUENCE_MAP_APPLICATION_H
#define INFLUENCE_MAP_APPLICATION_H
//-----------------------------------------------------------------
// Includes & Forward Declarations
//-----------------------------------------------------------------
#include "framework/EliteInterfaces/EIApp.h"

//--- Includes and Forward Declarations ---
#include "projects/Movement/SteeringBehaviors/SteeringHelpers.h"
#include "framework\EliteAI\EliteGraphs\EInfluenceMap.h"
#include "framework\EliteAI\EliteGraphs\EGraph2D.h"
#include "framework\EliteAI\EliteGraphs\EGridGraph.h"
#include "framework\EliteAI\EliteGraphs\EliteGraphUtilities\EGraphEditor.h"
#include "framework\EliteAI\EliteGraphs\EliteGraphUtilities\EGraphRenderer.h"

class NavigationColliderElement;
class SteeringAgent;
class Seek;
class Flee;
class Wander;
class InfluenceChasing;

//-----------------------------------------------------------------
// Application
//-----------------------------------------------------------------
class App_InfluenceMap final : public IApp
{
public:
	//Constructor & Destructor
	App_InfluenceMap() = default;
	virtual ~App_InfluenceMap() final;

	//App Functions
	void Start() override;
	void Update(float deltaTime) override;
	void UpdateUI();
	void Render(float deltaTime) const override;

	using InfluenceGrid = Elite::GridGraph<Elite::InfluenceNode, Elite::GraphConnection>;

private:
	Elite::InfluenceMap<InfluenceGrid>* m_pInfluenceGrid = nullptr;
	Elite::GraphEditor m_GridEditor{};
	Elite::GraphRenderer m_GraphRenderer{};

	bool m_EditGraphEnabled = false;
	bool m_RenderAsGraph = false;

	// Own Stuff
	InfluenceChasing* m_pInfluenceChasing{ nullptr };

	bool m_RenderAgents{ true };

private:
	//C++ make the class non-copyable
	App_InfluenceMap(const App_InfluenceMap&) = delete;
	App_InfluenceMap& operator=(const App_InfluenceMap&) = delete;
};
#endif