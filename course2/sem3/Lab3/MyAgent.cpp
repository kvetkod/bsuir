#include <iostream>
#include <vector>
#include <algorithm>
#include <sc-memory/sc_memory.hpp>


#include <sc-agents-common/utils/IteratorUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>


#include "MyAgent.hpp"

using namespace std;
using namespace utils;
    
ScAddrVector edges;
ScAddr graph1, graph2;
ScAddr CGraph;


namespace exampleModule
{
//итератор3 от определенной ноды по определенной дуге
ScIterator3Ptr iterator(unique_ptr<ScMemoryContext>& ms_context, ScAddr node, ScType type)
{
    ScIterator3Ptr it = ms_context->Iterator3(
            node,
            type,
            ScType::NodeConst
            );
    return it;
}
 //тот же итератор только в обратную сторону
ScIterator3Ptr iteratorR(unique_ptr<ScMemoryContext>& ms_context, ScAddr node, ScType type)
{
        ScIterator3Ptr it = ms_context->Iterator3(
                ScType::NodeConst,
                type,
                node
        );
        return it;
}

//достаем структуры графа 1 и 2
void GetGraphs(ScAddr actionNode1,unique_ptr<ScMemoryContext>& ms_context)
{
    //записываем адреса структур графов 1 и 2
    graph1=ms_context->GetEdgeSource(actionNode1);
    graph2=ms_context->GetEdgeTarget(actionNode1);
}

//добавление узла в граф-итог
void AddNode(unique_ptr<ScMemoryContext>& ms_context, ScAddr node)
{
    if(!ms_context->HelperCheckEdge(CGraph, node, ScType::EdgeAccessConstPosPerm))
    {
        ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, CGraph, node);
    }
}

//создание дуг в граф-итог между элементами-соседями
void CreatNewEdge(unique_ptr<ScMemoryContext>& ms_context, ScAddr node1, ScAddr node2)
{
    ScTemplate temp1,temp2, temp1r, temp2r;
    temp1.Triple(
            node1,
            ScType::EdgeUCommonVar,
            ScType::NodeVar >> "_var"
    );
    temp1r.Triple(

            ScType::NodeVar >> "_var",
            ScType::EdgeUCommonVar,
            node1
    );
    temp2.Triple(
            node2,
            ScType::EdgeUCommonVar,
            ScType::NodeVar >> "_var"
    );
    temp2r.Triple(

            ScType::NodeVar >> "_var",
            ScType::EdgeUCommonVar,
            node2
    );

    ScTemplateSearchResult res1, res2, res1r, res2r;
    ms_context->HelperSearchTemplateInStruct(temp1, graph1, res1);
    ms_context->HelperSearchTemplateInStruct(temp1r, graph1, res1r);
    ms_context->HelperSearchTemplateInStruct(temp2, graph2, res2);
    ms_context->HelperSearchTemplateInStruct(temp2r, graph2, res2r);


    for(int i=0; i<res1.Size(); i++)
    {
        for(int j=0; j<res2.Size(); j++)
        {
            if(res1[i]["_var"]!=res2[j]["_var"]) {
                AddNode(ms_context,res1[i]["_var"]);
                AddNode(ms_context,res2[j]["_var"]);
                ScAddr node = ms_context->CreateEdge(ScType::EdgeUCommonConst, res1[i]["_var"], res2[j]["_var"]);
                edges.push_back(node);
            }
        }
        for(int j=0; j<res2r.Size(); j++)
        {
            if(res1[i]["_var"]!=res2r[j]["_var"]) {
                AddNode(ms_context,res1[i]["_var"]);
                AddNode(ms_context,res2r[j]["_var"]);
                ScAddr node = ms_context->CreateEdge(ScType::EdgeUCommonConst, res1[i]["_var"], res2r[j]["_var"]);
                edges.push_back(node);
            }
        }
    }

    for(int i=0; i<res1r.Size(); i++)
    {
        for(int j=0; j<res2.Size(); j++)
        {
            if(res1r[i]["_var"]!=res2[j]["_var"]) {
                AddNode(ms_context,res1r[i]["_var"]);
                AddNode(ms_context,res2[j]["_var"]);
                ScAddr node = ms_context->CreateEdge(ScType::EdgeUCommonConst, res1r[i]["_var"], res2[j]["_var"]);
                edges.push_back(node);
            }
        }
        for(int j=0; j<res2r.Size(); j++)
        {
            if(res1r[i]["_var"]!=res2r[j]["_var"]) {
                AddNode(ms_context,res1r[i]["_var"]);
                AddNode(ms_context,res2r[j]["_var"]);
                ScAddr node = ms_context->CreateEdge(ScType::EdgeUCommonConst, res1r[i]["_var"], res2r[j]["_var"]);
                edges.push_back(node);
            }
        }
    }

}

//поиск одинаковых узлов в графе 1 и 2 + создание дуг их соседей
void Search(unique_ptr<ScMemoryContext>& ms_context)
{
    ScIterator3Ptr it1 = iterator(ms_context, graph1, ScType::EdgeAccessConstPosPerm);

    while(it1->Next())
    {
        ScIterator3Ptr it2 = iterator(ms_context, graph2, ScType::EdgeAccessConstPosPerm);
        while(it2->Next())
        {
            if(ms_context->HelperGetSystemIdtf(it1->Get(2))==ms_context->HelperGetSystemIdtf(it2->Get(2)))
            {
                CreatNewEdge(ms_context, it1->Get(2), it2->Get(2));
            }
        }
    }
}

//добавление дуг в граф-итог
void AddEdges(unique_ptr<ScMemoryContext>& ms_context)
{

    for(auto edge : edges){
        ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm, CGraph, edge);
    }
}

SC_AGENT_IMPLEMENTATION(MyAgent)
{
    SC_LOG_INFO("Agent started");
    ScAddr actionNode = otherAddr;
    GetGraphs(actionNode, ms_context);
    string name1 = ms_context->HelperGetSystemIdtf(graph1);
    string name2 = ms_context->HelperGetSystemIdtf(graph2);
    string name = name1+"*"+name2;
    CGraph = ms_context->CreateNode(ScType::NodeConstStruct);
    ms_context->HelperSetSystemIdtf(name, CGraph);
    Search(ms_context);
    AddEdges(ms_context);
    //utils::AgentUtils::finishAgentWork(&m_memoryCtx,actionNode,edges,true);
    return SC_RESULT_OK;
}
}
