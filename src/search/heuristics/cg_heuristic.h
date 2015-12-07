#ifndef HEURISTICS_CG_HEURISTIC_H
#define HEURISTICS_CG_HEURISTIC_H

#include "../heuristic.h"
#include "../priority_queue.h"

#include <string>
#include <vector>

class DomainTransitionGraph;
class GlobalState;
struct ValueNode;


namespace CGHeuristic {
class CGCache;

class CGHeuristic : public Heuristic {
    std::vector<AdaptiveQueue<ValueNode *> *> prio_queues;

    CGCache *cache;
    int cache_hits;
    int cache_misses;

    int helpful_transition_extraction_counter;

    void setup_domain_transition_graphs();
    int get_transition_cost(const GlobalState &state, DomainTransitionGraph *dtg, int start_val, int goal_val);
    void mark_helpful_transitions(const GlobalState &state, DomainTransitionGraph *dtg, int to);
protected:
    virtual void initialize();
    virtual int compute_heuristic(const GlobalState &state);
public:
    CGHeuristic(const Options &opts);
    ~CGHeuristic();
    virtual bool dead_ends_are_reliable() const;
};
}

#endif