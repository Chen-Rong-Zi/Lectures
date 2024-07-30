# include "ants.h"
void ants_lose() {
    throw AntsLoseException();
}

void ants_win() {
    throw AntsWinException();
}

void Place::__init__() {
    if ( this->exit != nullptr )
        this->exit->entrance = this->shared_from_this();
}
void Place::add_insect(std::shared_ptr<Insect> insect) {
    /** Asks the insect to add itself to the current place. This method exists so
     *  it can be enhanced in subclasses.
     */
    if ( DEBUG )print("in Place::add_insect");
    insect->add_to(this->shared_from_this());
}

void Place::remove_insect(std::shared_ptr<Insect> insect) {
    /**
     * Asks the insect to remove itself from the current place. This method exists so it can be enhanced in subclasses.
     */
    // print("in remove_insect, insect = ", insect);
    print("I am ", insect->get_name(), "living in ", this->to_string(), " i am going to be removed from ", this->name, " my health:", insect->health);
    insect->remove_from(this->shared_from_this());
    if ( DEBUG )print("pass remove_insect");
}

std::string Place::to_string() {
    return this->name;
}

void Insect::reduce_health(double amount) {
    print("I am ", this->get_name(), " the attack was, ", amount, "  i only have ", this->health);
    this->health -= amount;
    if ( this->health <= 0 ) {
        this->death_callback();
        // print("pass death_callback");
        this->place->remove_insect(this->shared_from_this());
        // print("pass remove_insect");
    }
}

void Insect::action(std::shared_ptr<GameState> gamestate) {
    /** The action performed each turn.
     *  gamestate -- The GameState, used to access game state information.
     */
    throw std::runtime_error("action Not Implemented Error!");
}

void Insect::death_callback() {
    /** overriden by the gui
     */
    // print("in death_callback");
    this->dead_behavior.updateGuiState(this->shared_from_this());
}

void Insect::add_to(std::shared_ptr<Place> place) {
    /**
     * Add this Insect to the given Place
     * By default just sets the place attribute, but this should be overriden in the subclasses
     *     to manipulate the relevant attributes of Place
     */
    if ( DEBUG ) print("enter add_to");
    this->place = place;
}

void Insect::remove_from(std::shared_ptr<Place> place) {
    this->place = nullptr;
}

std::string Insect::get_name() {
    return "Insect" + std::to_string(this->health) + this->place->to_string();
}


std::string Bee::get_name() {
    return "Bee";
}

bool Ant::is_container() {
   return false;
}

bool ContainerAnt::is_container() {
   return true;
}

int Ant::get_food_cost() {
    throw std::runtime_error("ant does not have food_cost!");
}

int ThrowerAnt::get_food_cost() {
    return this->food_cost;
}
int ShortThrower::get_food_cost() {
    return this->food_cost;
}

int LongThrower::get_food_cost() {
    return this->food_cost;
}

int FireAnt::get_food_cost() {
    return this->food_cost;
}

int WallAnt::get_food_cost() {
    return this->food_cost;
}
int HungryAnt::get_food_cost() {
    return this->food_cost;
}

int BodyguardAnt::get_food_cost() {
    return this->food_cost;
}

int TankAnt::get_food_cost() {
    return this->food_cost;
}
int ScubaThrower::get_food_cost() {
    return this->food_cost;
}

int AntRemover::get_food_cost() {
    return this->food_cost;
}

std::string Ant::get_name() {
    throw std::runtime_error("ant does not have a type name!");
}

int QueenAnt::get_food_cost() {
    return this->food_cost;
}

std::string QueenAnt::get_name() {
    return this->name;
}

std::string ThrowerAnt::get_name() {
    return this->name;
}
std::string ShortThrower::get_name() {
    return this->name;
}

std::string LongThrower::get_name() {
    return this->name;
}

std::string FireAnt::get_name() {
    return this->name;
}

std::string WallAnt::get_name() {
    return this->name;
}
std::string HungryAnt::get_name() {
    return this->name;
}

std::string BodyguardAnt::get_name() {
    return this->name;
}

std::string TankAnt::get_name() {
    return this->name;
}
std::string ScubaThrower::get_name() {
    return this->name;
}

std::string AntRemover::get_name() {
    return this->name;
}

void Ant::action(std::shared_ptr<GameState> gamestate) {
    print("I am a ", this->get_name(), " and i will do nothing");
}

bool Ant::can_contain(std::shared_ptr<Ant> other) {
    return false;
}

std::shared_ptr<Ant> Ant::get_self() {
    return std::dynamic_pointer_cast<Ant>(this->shared_from_this());
}
void Ant::store_ant(std::shared_ptr<Ant> other) {
    throw std::runtime_error("store_ant Not Implemented");
}

void Ant::remove_ant(std::shared_ptr<Ant> other) {
    throw std::runtime_error("store_ant Not Implemented");
}

void Ant::add_to(std::shared_ptr<Place> place) {
    if ( DEBUG )print("in ant::add_to");
    auto self = this->get_self();
    if ( DEBUG )print("pass slef get_self");
    if (place->ant == nullptr) {
        print("place->ant = nullptr");
        place->ant = self;
    } else if ( place->ant->is_container() && place->ant->can_contain(self) ) {
        print("place->ant if ContainerAnt and it can contain");
        place->ant->store_ant(self);
    } else if (  this->is_container() && this->can_contain(place->ant) ) {
        print("i am a ContainerAnt and i can contains place->ant");
        this->store_ant(place->ant);
        place->ant = self;
    } else {
        print("place->ant is not nullptr but you can not place this ant in this place");
        throw AddInsectError();
    }
    this->Insect::add_to(place);
    if ( DEBUG )print("pass Insect::add_to");
}

void Ant::remove_from(std::shared_ptr<Place> place) {
    auto self = this->get_self();
    if ( place->ant == self )
        place->ant = nullptr;
    else if ( place->ant == nullptr ) {
        print(this->get_name(), "Not in ", place->to_string());
        throw std::runtime_error(this->get_name() + "Not In " + place->to_string());
    } else {
        place->ant->remove_ant(self);
    }
    this->Insect::remove_from(place);
}

void Ant::buff() {
    /** Double this ants's damage, if it has not already been buffed.
     */

    /* TODO <++>*/
    // if hasattr(self, "buffed"):
        // return
    /* TODO <++>*/
    this->damage = this->damage * 2;
    this->buffed = true;
}
int HarvesterAnt::get_food_cost() {
    return this->food_cost;
}

std::string HarvesterAnt::get_name() {
    return this->name;
}

std::shared_ptr<Bee> ThrowerAnt::nearest_bee() {
    auto walk = this->place;
    int pos = 0;
    int max_range = this->get_max_range();
    int min_range = this->get_min_range();
    while ( walk != nullptr && (!walk->is_hive())  ) {
        print("thrower is aiming at", walk->name);
        if ( walk->bees.len() != 0 && pos <= max_range && pos >= min_range )
            return random_bee(walk->bees);
            // return random_bee(walk->bees);
        walk = walk->entrance;
        pos += 1;
    }
    print("no bee found!");
    return nullptr;
}

void ThrowerAnt::throw_at(std::shared_ptr<Bee> target) {
    if ( DEBUG )print("in throw_at");
    if ( target != nullptr ) {
        print("i am ", this->get_name(), " and i am going to attck a ", target->get_name());
        target->reduce_health(this->damage);
    }
    if ( DEBUG )print("pass throw_at");
}

void FireAnt::reduce_health(double amount) {
    /* Reduce health by AMOUNT, and remove the FireAnt from its place if it has no health remaining.*/
    // auto bees = shallow_copy(this->place->bees);
    for ( auto bee : this->place->bees ) {
        if ( this->health - amount > 0 )
            bee->reduce_health(amount);
        else
            bee->reduce_health(amount + this->damage);
    }
    Ant::reduce_health(amount);
}

void ContainerAnt::reduce_health(double amount) {
    /* Reduce health by AMOUNT, and remove the FireAnt from its place if it has no health remaining.*/
    // auto bees = shallow_copy(this->place->bees);
    for ( auto bee : this->place->bees ) {
        if ( this->health - amount > 0 )
            bee->reduce_health(amount);
        else
            bee->reduce_health(amount + this->damage);
    }
    Ant::reduce_health(amount);
}

bool ContainerAnt::can_contain(std::shared_ptr<Ant> other) {
    if ( this->ant_contained == nullptr && (other->is_container() == false) )
        return true;
    return false;
}

void ContainerAnt::store_ant(std::shared_ptr<Ant> ant) {
    this->ant_contained = ant;
}

void ContainerAnt::remove_ant(std::shared_ptr<Ant> ant) {
    this->ant_contained = nullptr;
}

void ContainerAnt::remove_from(std::shared_ptr<Place> place) {
    if ( place->ant ==  this->get_self() ) {
        place->ant = this->ant_contained;
        Insect::remove_from(place);
    } else {
        Ant::remove_from(place);
    }
}

void TankAnt::action(std::shared_ptr<GameState> gamestate) {
    for ( auto bee : this->place->bees )
        bee->reduce_health(this->damage);
    if ( this->ant_contained != nullptr )
        this->ant_contained->action(gamestate);
}


void HarvesterAnt::action(std::shared_ptr<GameState> gamestate) {
    /**
     *Produce 1 additional food for the colony.
     *gamestate -- The GameState, used to access game state information.
     */
    gamestate->food += 1;
}

void ThrowerAnt::action(std::shared_ptr<GameState> gamestate) {
    this->throw_at(this->nearest_bee());
}

void HungryAnt::action(std::shared_ptr<GameState> gamestate) {
    if ( this->chew_countdown <= 0 && this->place->bees.len() != 0 ) {
        std::shared_ptr<Bee> bee = random_bee(this->place->bees);
        bee->reduce_health(bee->health);
        this->chew_countdown = this->chew_duration;
    } else {
        this->chew_countdown -= 1;
    }
}

void ContainerAnt::action(std::shared_ptr<GameState> gamestate) {
    if ( this->ant_contained != nullptr )
        this->ant_contained->action(gamestate);
}

List<std::shared_ptr<Ant>> QueenAnt::behind_ants(std::shared_ptr<Place> place) {
    if ( place == nullptr )
        return List<std::shared_ptr<Ant>>();
    return cons(place->ant, behind_ants(place->exit));
}

void QueenAnt::reduce_health(double amount) {
    /**
     *Reduce health by AMOUNT, and if the QueenAnt has no health remaining, signal the end of the game.
     */
    if ( amount < this->health )
        Ant::reduce_health(amount);
    else {
        print("ants_lose exception!");
        ants_lose();
    }
}



QueenAnt::QueenAnt(std::shared_ptr<GameState> gamestate) {
    gamestate->has_queen = true;
};

void QueenAnt::action(std::shared_ptr<GameState> gamestate) {
    /**
     *A queen ant throws a leaf, but also doubles the damage of ants
     * in her tunnel.
     */
    // 因为Queen直接继承自ant，所以没有实现action的父类
    ScubaThrower::action(gamestate);
    auto ants = this->behind_ants(this->place->exit);
    this->is_waterproof = true;
}


void Bee::sting(std::shared_ptr<Ant> ant) {
    ant->reduce_health(this->damage);
}

void Bee::move_to(std::shared_ptr<Place> place) {
    this->place->remove_insect(this->get_self());
    place->add_insect(this->get_self());
}


void Bee::add_to(std::shared_ptr<Place> place) {
    place->bees.append(this->get_self());
    Insect::add_to(place);
}

void Bee::remove_from(std::shared_ptr<Place> place) {
    if ( DEBUG )print("in bee::remove_from");
    this->get_self();
    if ( DEBUG )print("pass get_self()");
    place->bees.remove(this->get_self());
    print("位置", place->to_string(), "还剩下place->bees.len() = ", this->place->bees.len());
    if ( DEBUG )print("pass palce->bees.remove(this->get_self())");
    Insect::remove_from(place);
    if ( DEBUG )print("insect::remove_from(place)");
}


void Bee::action(std::shared_ptr<GameState> gamestate) {
    if ( DEBUG )print("in bee::action");
    print("this->place = ", this->place->name);
    auto destination = this->place->exit;
    if ( DEBUG )print("pass this->palce->exit");
    if ( this->blocked() ) {
        print("bee is blocked");
        this->sting(this->place->ant);
    } else if ( this->health > 0 && destination != nullptr ) {
        this->move_to(destination);
    }
    print("pass bee action");
}


void Hive::strategy(std::shared_ptr<GameState> gamestate) {
    auto places = map_to_list(gamestate->places);
    auto place_ptrs = map(places, [=] (auto str_place) {return str_place.second;});
    auto exits = filter(place_ptrs, [&] (auto p) {return p->entrance == this->get_self();});
    for ( auto bee : this->assault_plan->get(gamestate->time) )
    {
        if ( DEBUG )print("in hive::strategy");
        bee->dead_behavior = InsectDeadBehavior(gamestate->gui);
        bee->move_to(exits.random_choice());
        // bee->move_to(car(exits));
        gamestate->active_bees.append(bee);
    }
}

void Hive::__init__() {
    this->bees = List<std::shared_ptr<Bee>>();
    for ( auto it : this->assault_plan->all_bees() )
    {
        this->add_insect(it);
        if ( DEBUG == 1 ) print("pass add_insect");
    }
}

Hive::Hive(std::shared_ptr<AssaultPlan> assault_plan):
    Place("Hive", nullptr),
    assault_plan(assault_plan)
{};

void GameState::__init__() {
    this->deploy_ant_strategy = std::make_shared<DeployAntStrategy>(this->shared_from_this());
    this->place_manager->set_gamestate(this->shared_from_this());
    if ( DEBUG )print("pass set_gamestate");
    this->configure(this->beehive, this->place_manager);
    if ( DEBUG )print("pass configure");
}

void GameState::configure(std::shared_ptr<Hive> beehive, std::shared_ptr<WetLayoutManager> place_manager) {
    this->base   = std::make_shared<AntHomeBase>("Ant Home Base");
    if ( DEBUG )print("AntHomeBase make_shared");
    this->places = std::map<std::string, std::shared_ptr<Place>>();
    if ( DEBUG )print("pass Place make_shared");
    this->bee_entrances = List<std::shared_ptr<Place>>();
    if ( DEBUG )print("pass List<Place> make_shared");
    place_manager->register_place(this->beehive, false);
    if ( DEBUG )print("pass place_manager register_place");
    place_manager->set_layout(this->base, this->dimensions->first, this->dimensions->second, 3);
    if ( DEBUG )print("pass place_manager set_layout");
}

void GameState::ants_action() {
    for (auto insect : this->ants() ) {              // Ants take actions
        auto ant = std::dynamic_pointer_cast<Ant>(insect);
        print("i am a ", ant->get_name(), " I am doing my action");
        if ( ant->health > 0 )
            ant->action(this->shared_from_this());
    }
}

void GameState::bees_action() {
    this->active_bees = filter(this->active_bees, [=] (auto bee) {
            return (bee->health > 0) && (bee->place != nullptr);
        });
    for (auto bee : this->active_bees) {
        print("I am", this->gui->beeToId[bee], "bee->health = ", bee->health);
        print("i am in active_bees, id: ", this->gui->beeToId[bee], " in ", (bee->place)? bee->place->to_string():"null", " health = ", bee->health);
        print("尝试删除bee, active_bees.count_if(bee) = ", active_bees.count_if([=] (auto ele) {return ele == bee;}));
        print("I am", this->gui->beeToId[bee], "bee->health = ", bee->health);
        print("this->active_bees还剩下", this->active_bees.len(), "个");
        if ( bee->health > 0 )
            bee->action(this->shared_from_this());
    }
}

std::generator<std::shared_ptr<GameState>> GameState::set_game() {
    /* Simulate an attack on the ant colony (i.e., play the game).   */
    while (true) {
        // if ( DEBUG )print("in while ( loop )");
        // if ( DEBUG )print("enter beehive strategy");
        this->beehive->strategy(this->shared_from_this());         // Bees invade
        // if ( DEBUG )print("pass beehive strategy");
        // if ( DEBUG )print("pass beehive->strategy");
        // if ( DEBUG )print("in GameState::simulate");
        this->deploy_ant_strategy->apply();
        // if ( DEBUG )print("pass apply");
        co_yield this->shared_from_this();
        // if ( DEBUG )print("pass co_yield");
        this->ants_action();
        // if ( DEBUG )print("pass ants_action");
        this->bees_action();
        // if ( DEBUG )print("pass bees_action");
        if ( this->bees().len() == 0 )
            throw AntsWinException();
        this->time += 1;
    }
}

std::shared_ptr<GameState> GameState::simulate() {
    return *(this->game.begin());
}

std::shared_ptr<Ant> GameState::deploy_ant(std::string place_name, std::string ant_type_name) {
    /** Place an ant if enough food is available.
    * This method is called by the current strategy to deploy ants.
    * **/
    if ( DEBUG )print("in GameState::deploy_ant");
    std::shared_ptr<Ant> ant = InsectFactory::newAnt(ant_type_name, this->shared_from_this());
    if ( DEBUG )print("pass InsectFactory::newant");
    if ( ant == nullptr )
        return nullptr;
    if ( DEBUG )print("place_name = ", place_name);
    if ( DEBUG )print(this->places[place_name]->name);
    try {
        this->places[place_name]->add_insect(ant);
        if ( DEBUG )print("in ", place_name, " put a ", ant->get_name());
        if ( DEBUG )print("webstate[\"places\"] 的ant为 = ", (this->places[place_name]->ant)?this->places[place_name]->ant->get_name() : "null");
    } catch (AddInsectError) {
        return nullptr;
    }
    if ( DEBUG )print("pass add insect");
    this->food -= ant->get_food_cost();
    print("ant: ", ant->get_name(), " food_cost ", ant->get_food_cost(), "  left_food ", this->food);
    return ant;
}

void GameState::remove_ant(std::string place_name) {
    /*  Remove an Ant from the game.  */
    auto place = this->places[place_name];
    if ( place->ant != nullptr )
        place->remove_insect(place->ant);
}


List<std::shared_ptr<Insect>> GameState::ants() {
    auto place_list = map_to_list(this->places);
    auto places_with_ant = filter(place_list, [=] (std::pair<std::string, std::shared_ptr<Place>> name_place) {
            return name_place.second->ant != nullptr;
        });
    return map(places_with_ant, [=] (auto name_place) { return std::dynamic_pointer_cast<Insect>(name_place.second->ant); });
}

List<std::shared_ptr<Insect>> GameState::bees() {
    auto place_list = map_to_list(this->places);
    auto bee_lists = map(place_list, [=] (auto name_place) {
            return map(name_place.second->bees, [=] (auto bee) {
                    return std::dynamic_pointer_cast<Insect>(bee);
                });
            });
    return reduce([=] (List<std::shared_ptr<Insect>> pre, List<std::shared_ptr<Insect>> curr) {return pre + curr;}, bee_lists, List<std::shared_ptr<Insect>>());
    // return List<std::shared_ptr<Insect>>();
}


List<std::shared_ptr<Insect>> GameState::insects() {
    return this->ants();
}


std::string GameState::to_string() {
    std::string status = std::string(" (Food: ") + std::to_string(this->food) + std::string(", Time: ") + std::to_string(this->time) + std::string(")");
    auto ins_str = map(this->insects(), [=] (auto ins) {
            return ins->get_name();
        });
    auto res = reduce([=] (auto pre, auto curr) {
            return pre + ", " + curr;
            }, ins_str, std::string(""));
    return res + status;
}

std::map<int, List<std::shared_ptr<Bee>>> AssaultPlan::add_wave(std::string bee_name, double bee_health, int time, int count) {
    /*  Add a wave at time with count Bees that have the specified health.  */
    auto new_bees = map(range(0, count, 1), [=] (int i) {
            return InsectFactory::newBee(bee_name, bee_health);
        });
    if ( this->plan.find(time) == this->plan.end() )
        this->plan[time] = new_bees;
    else {
        this->plan[time].extend(new_bees);
    }
    return this->plan;
}


List<std::shared_ptr<Bee>> AssaultPlan::all_bees() {
    /*  Place all Bees in the beehive and return the list of Bees.  */
    auto place_with_bee = map(map_to_list(this->plan), [=] (auto int_beeptr) {
            return filter(int_beeptr.second, [=] (auto bee) {
                    return bee != nullptr;
                });
            });
    return reduce([=] (auto pre, auto curr) {
            return pre + curr;
        }, place_with_bee, List<std::shared_ptr<Bee>>());
}


List<std::shared_ptr<Bee>> AssaultPlan::get(int time) {
    if ( this->plan.find(time) == this->plan.end() )
        return List<std::shared_ptr<Bee>>();
    return this->plan[time];
}

std::shared_ptr<Ant> InsectFactory::newAnt(std::string type_name, std::shared_ptr<GameState> gamestate) {
    if ( InsectFactory::cost_map.find(type_name) == InsectFactory::cost_map.end() ) {
        print("type_name: ", type_name, " can not find in factory");
        throw std::runtime_error(type_name + " Not In cost_map ！");
    } else if ( InsectFactory::cost_map[type_name] > gamestate->food ) {
        return nullptr;
    print("making a new ant", " gamestate->gui = ", gamestate->gui);
    if ( gamestate->gui == nullptr ) {
        throw std::runtime_error("asdf");
    }
    } else if ( type_name == "Harvester" ) {
        auto ant = std::make_shared<HarvesterAnt>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Thrower" ) {
        auto ant = std::make_shared<ThrowerAnt>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Short" ) {
        auto ant = std::make_shared<ShortThrower>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Fire" ) {
        auto ant = std::make_shared<FireAnt>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Wall" ) {
        auto ant = std::make_shared<WallAnt>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Bodyguard" ) {
        auto ant = std::make_shared<BodyguardAnt>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Hungry" ) {
        auto ant = std::make_shared<HungryAnt>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Tank" ) {
        auto ant = std::make_shared<TankAnt>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Scuba" ) {
        auto ant = std::make_shared<ScubaThrower>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Queen" && gamestate->has_queen == false ) {
        auto ant = std::make_shared<QueenAnt>(gamestate);
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        gamestate->has_queen = true;
        return ant;
    } else if ( type_name == "Long" ) {
        auto ant = std::make_shared<LongThrower>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else if ( type_name == "Remover" ) {
        auto ant = std::make_shared<AntRemover>();
        ant->dead_behavior = InsectDeadBehavior(gamestate->gui);
        return ant;
    } else {
        print("no such ant error");
        throw std::runtime_error(type_name + "No such ANT Error!");
    }
}



std::shared_ptr<Bee> BeeToBeMade::contstruct(std::shared_ptr<Gui> gui) {
    auto bee = std::make_shared<Bee>();
    bee->dead_behavior = InsectDeadBehavior(gui);
    return bee;
}


std::shared_ptr<Wasp> WaspToBeMade::contstruct(std::shared_ptr<Gui> gui) {
    auto bee = std::make_shared<Wasp>();
    bee->dead_behavior = InsectDeadBehavior(gui);
    return bee;
}

std::shared_ptr<NinjaBee> NinjaTobeMade::contstruct(std::shared_ptr<Gui> gui) {
    auto bee = std::make_shared<NinjaBee>();
    bee->dead_behavior = InsectDeadBehavior(gui);
    return bee;
}

std::shared_ptr<Bee> InsectFactory::newBee(std::string type_name, double health) {
    if ( InsectFactory::cost_map.find(type_name) == InsectFactory::cost_map.end() ) {
        if ( DEBUG )print("found bee!");
        throw std::runtime_error(type_name + " Not In cost_map ！");
    } else if ( type_name == "Bee" ) {
        return std::make_shared<Bee>(health);
    } else if ( type_name == "Wasp" ) {
        return std::make_shared<Wasp>(health);
    } else if ( type_name == "NinjaBee" ) {
        return std::make_shared<NinjaBee>(health);
    } else {
        throw std::runtime_error(type_name + "No such Bee Error!");
    }
}

std::shared_ptr<Bee> random_bee(List<std::shared_ptr<Bee>> bees) {
    if ( bees.len() != 0 )
        return bees.random_choice();
    throw std::runtime_error("bees is empty!");
}

void WetLayoutManager::register_place(std::shared_ptr<Place> place, bool is_bee_entrance) {
    if ( DEBUG )print("pass shared_ptr<Place> param init");
    this->gamestate->places[place->name] = place;
    if ( DEBUG )print(place->name, "registerted to", "beehive");
    if ( DEBUG )print("pass gamestate assign place to this->places[place->name]]");
    if (is_bee_entrance) {
        place->entrance = this->gamestate->beehive;
        this->gamestate->bee_entrances.append(place);
        if ( DEBUG )print("pass append");
    }
}


void WetLayoutManager::set_layout(std::shared_ptr<Place> base, int tunnels = 3, int length = 9, int moat_frequency = 3) {
    /*  Register a mix of wet and and dry places.  */
    if ( DEBUG )print("pass shared_ptr<Place> base init");
    print("  tunnels = ", tunnels, "  length = ", length, "  moat_frequency = ", moat_frequency);
    for ( int tunnel = 0; tunnel < tunnels; tunnel += 1 )
    {
        auto exit = base;
        for ( int step = 0; step < length; step += 1 )
        {
            if ( moat_frequency != 0 && (step + 1) % moat_frequency == 0 )
                exit = std::make_shared<Water>(std::string("water_") + std::to_string(tunnel) + "_" + std::to_string(step), exit);
            else
                exit = std::make_shared<Place>(std::string("tunnel_") + std::to_string(tunnel) + "_" + std::to_string(step), exit);
            if ( DEBUG )print("pass make_shared<Place> or make_shared<Water>");
            exit->__init__();
            if ( DEBUG )print("step == length - 1  :", step == length - 1);
            this->register_place(exit, step == length - 1);
            if ( DEBUG )print("this->register_place");
        }
    }
}

void WetLayoutManager::set_gamestate(std::shared_ptr<GameState> gamestate) {
    this->gamestate = gamestate;
}

void DryLayoutManager::set_layout(std::shared_ptr<Place> base, int tunnels = 3, int length = 9, int moat_frequency = 0) {
    /*  Register dry tunnels.  */
    this->WetLayoutManager::set_layout(base, tunnels, length, moat_frequency);
}

void DeployAntStrategy::initialize_colony_graphics() {
    if ( DEBUG )print("init initialize_colony_graphics");
    this->gamestate->gui->saveState("strategyTime", 3);
    this->gamestate->gui->saveState("food", this->gamestate->food);
    if ( DEBUG )print("pass saveState food");
    this->gamestate->gui->_init_places(gamestate);
    if ( DEBUG )print("pass _init_places");
    if ( DEBUG )print("pass initialize_colony_graphics");
    // this->gamestate->gui->saveState("places", this->gamestate->gui->webstate["places"]);
    this->gamestate->gui->initialized = true;
    if ( DEBUG )print(this->gamestate->gui->webstate.dump());
}


std::shared_ptr<GameState> DeployAntStrategy::apply() {
    print("DeployAntStrategy");
    return nullptr;
}


std::shared_ptr<AssaultPlan> make_test_assault_plan() {
    auto plan = std::make_shared<AssaultPlan>();
    plan->add_wave("Bee", 3, 2, 1);
    plan->add_wave("Bee", 3, 3, 1);
    if ( DEBUG ) print("leave test plan");
    return plan;
}


std::shared_ptr<AssaultPlan> make_easy_assault_plan() {
    std::shared_ptr<AssaultPlan> plan = std::make_shared<AssaultPlan>();
    for (auto time : range(3, 16, 2)) {
        plan->add_wave("Bee",      3,  time, 1);
    }
    plan->add_wave("Wasp",     3,  4,    1);
    plan->add_wave("NinjaBee", 3,  8,    1);
    //plan->add_wave("Hornet",   3,  12,   1);
    //plan->add_wave("Boss",     15, 16,   1);
    return plan;
}



std::shared_ptr<AssaultPlan> make_normal_assault_plan() {
    auto  plan = std::make_shared<AssaultPlan>();
    for (auto time : range(3, 16, 2)) {
        plan->add_wave("Bee", 3, time, 2);
    }
    plan->add_wave("Wasp",     3, 4,  1);
    // plan->add_wave("NinjaBee", 3, 8,  1);
    //plan->add_wave("Hornet",   3, 12, 1);
    plan->add_wave("Wasp",     3, 16, 1);
    //// Boss Stage
    for (auto time : range(21, 30, 2)) {
        plan->add_wave("Bee", 3, time, 2);
    }
    plan->add_wave("Wasp",     3,  22, 2);
    //plan->add_wave("Hornet",   3,  24, 2);
    plan->add_wave("NinjaBee", 3,  26, 2);
    //plan->add_wave("Hornet",   3,  28, 2);
    //plan->add_wave("Boss",     20, 30, 1);
    return plan;
}

std::shared_ptr<AssaultPlan> make_hard_assault_plan() {
    auto plan = std::make_shared<AssaultPlan>();
    for (auto time : range(3, 16, 2)) {
        plan->add_wave("Bee", 4, time, 2);
    }
    //plan->add_wave("Hornet",   4, 4,  2);
    plan->add_wave("Wasp",     4, 8,  2);
    plan->add_wave("NinjaBee", 4, 12, 2);
    plan->add_wave("Wasp",     4, 16, 2);
    //// Boss Stage
    for (auto time : range(21, 30, 2)) {
        plan->add_wave("Bee", 4, time, 3);
    }
    plan->add_wave("Wasp",     4,  22, 2);
    //plan->add_wave("Hornet",   4,  24, 2);
    plan->add_wave("NinjaBee", 4,  26, 2);
    //plan->add_wave("Hornet",   4,  28, 2);
    //plan->add_wave("Boss",     30, 30, 1);
    return plan;
}

std::shared_ptr<AssaultPlan> make_extra_hard_assault_plan() {
    auto plan = std::make_shared<AssaultPlan>();
    //plan->add_wave("Hornet", 5, 2, 2);
    for (auto time : range(3, 16, 2)) {
        plan->add_wave("Bee", 5, time, 2);
    }
    //plan->add_wave("Hornet",   5, 4,  2);
    plan->add_wave("Wasp",     5, 8,  2);
    plan->add_wave("NinjaBee", 5, 12, 2);
    plan->add_wave("Wasp",     5, 16, 2);
    //// Boss Stage
    for (auto time : range(21, 30, 2)) {
        plan->add_wave("Bee", 5, time, 3);
    }
    plan->add_wave("Wasp",     5,  22, 2);
    //plan->add_wave("Hornet",   5,  24, 2);
    plan->add_wave("NinjaBee", 5,  26, 2);
    //plan->add_wave("Hornet",   5,  28, 2);
    //plan->add_wave("Boss",     30, 30, 2);
    return plan;
}



std::shared_ptr<GameState> game_init() {
    /*  Reads command-line arguments and starts a game with those options  */
    std::shared_ptr<AssaultPlan> assault_plan = make_normal_assault_plan();
    int tunnel_length = 10;
    int num_tunnels = 3;
    int food = 10;
    auto beehive = std::make_shared<Hive>(assault_plan);
    beehive->__init__();
    auto dimensions = std::make_shared<std::pair<int, int>>(num_tunnels, tunnel_length);
    if ( DEBUG )print("pass dimensions");
    if ( DEBUG )print("pass InteractiveStrategy");
    auto gamestate = std::make_shared<GameState>(beehive, std::make_shared<WetLayoutManager>(), dimensions, food);
    if ( DEBUG )print("pass gamestate constructor");
    gamestate->__init__();
    if ( DEBUG )print("pass interact");
    return gamestate;
}

std::shared_ptr<Gui> start_with_option() {
    std::shared_ptr<GameState> gamestate = game_init();
    return std::make_shared<Gui>(gamestate);
}


void Gui::clean_state() {
    this->initialized     = false;
    this->active          = true;
    this->gameOver        = false;
    this->gamestate       = nullptr;
    this->currentBeeId    = 0;
    this->currentInsectId = 0;
    this->insects         = List<int>();

    this->insectToId      = std::map<std::shared_ptr<Insect>, int>();
    this->beeToId         = std::map<std::shared_ptr<Bee>,    int>();
    this->beeLocations    = std::map<int,                     std::string>();
    this->webstate        = json::parse("{}");
    this->webstate["time"] = 0;
    this->webstate["deadinsects"] = json::array();
    this->webstate["deadbees"]    = json::array();
    this->webstate["ant_types"]   = json::array();
    for_each(Gui::INSECT_FILES, [&] (auto pair) {
        json data = R"({})"_json;
        data["name"] = pair.first;
        data["cost"] = InsectFactory::cost_map[pair.first];
        data["img"] = pair.second;
        this->webstate["ant_types"].push_back(data);
    });
}

void Gui::set_place_name_by_row_col(std::string row, std::string col, std::string name) {
    this->webstate["places"][row][col] = R"({
        "name": "",
        "type": "tunnel",
        "water": 0,
        "insects": {}
    })"_json;
    this->webstate["places"][row][col]["name"] = name;
    if ( name.find("water") != std::string::npos )
        this->webstate["places"][row][col]["water"] = 1;
}

void Gui::set_place_by_name(std::string name) {
    this->webstate["places"][gamestate->beehive->name] = R"({
        "name": "",
        "type": "beehive",
        "water": 0,
        "insects": []
    })"_json;
    print("set this->places[", gamestate->beehive->name, "][\"name\"] = ", name);
    this->webstate["places"][gamestate->beehive->name]["name"] = name;
}

// Gui::Gui()
// {
    // this->active = true;
    // this->clean_state();
// };

void Gui::__init__()
{
    this->gamestate->gui = this->shared_from_this();
};

Gui::Gui(std::shared_ptr<GameState> gamestate) {
    this->active = true;
    this->clean_state();
    if ( DEBUG )print("pass clean_state");
    this->gamestate = gamestate;
    if ( DEBUG )print("pass set gamestate");
    this->webstate["ant_types"] = json::array();
    for_each(Gui::INSECT_FILES, [&] (auto pair) {
        json data = R"({})"_json;
        data["name"] = pair.first;
        data["cost"] = InsectFactory::cost_map[pair.first];
        data["img"] = pair.second;
        this->webstate["ant_types"].push_back(data);
    });
}


void Gui::new_game() {
    print("Trying to start new game");
    this->clean_state();      // resets GUI state
    // *this->gamestate->begin();
    // this->gameOver = true;
}

void Gui::kill() {
    this->active = false;
}


json Gui::exit_game(json data) {
    this->active = false;
    return R"({
        "hello": 1
    })"_json;
}

std::string Gui::start_game() {
    if ( DEBUG )print("in gui::start game");
    this->clean_state();
    if ( DEBUG )print("pass clean_state");
    auto gamestate = game_init();
    if ( DEBUG )print("pass game_init");
    this->gamestate = gamestate;
    this->__init__();
    return std::string("gamestart");
}

std::string Gui::get_insect_img_file(std::string name) {
    return Gui::INSECT_FILES[name];
}

std::string Gui::getState(long long now) {
    static long long lasttime = 0;
    /*  Get our message from JSON  */
    if ( this->initialized == false ) {
        this->gamestate->deploy_ant_strategy->initialize_colony_graphics();
        this->initialized = true;
    }

    if ( (now - lasttime) <= 1000 )
        return this->webstate.dump();
    lasttime = now;
    int time = this->webstate["time"].get<int>();
    this->saveState("time", time + 1);
    if ( time % 2 != 0 || time == 0 ) {
        return this->webstate.dump();
    }
    this->gamestate->gui->_update_control_panel(this->gamestate);

    try {
        std::shared_ptr<GameState> res = this->gamestate->simulate();
    } catch (AntsWinException) {
        print("All bees are vanquished. You win!");
        this->saveState("gameOver", 1);
        this->saveState("winner", 1);
        this->kill();
    } catch (AntsLoseException) {
        print("The ant queen has perished. Please try again.");
        this->saveState("gameOver", 1);
        this->saveState("winner", 0);
        this->kill();
    } catch (GameOverException) {
        print("game over exception");
        this->saveState("gameOver", 1);
        this->saveState("Winner", 0);
        this->kill();
    }
    return this->webstate.dump();
}

template <typename T>
void Gui::saveState(std::string key, T val) {
    /*  Saves our game object to JSON file  */
    this->webstate[key] = val;
}

std::string Gui::get_place_row(std::string name) {
    return split(name, "_").car_n(1);
}

std::string Gui::get_place_column(std::string name) {
    return split(name, "_").car_n(2);
}

void Gui::_init_places(std::shared_ptr<GameState> gamestate) {
    /*  Calculate all of our place data  */
    this->webstate["places"] = R"({})"_json;
    if ( DEBUG )print("gamestate->places = ");
    if ( DEBUG )print("pass this->places = R\"({})\"_json");
    // this->images = {'AntQueen': dict()}
    int rows = 0,  cols = 0;
    std::string out_name;
    if ( DEBUG )print(gamestate->places.size());
    for ( auto [name, place] : gamestate->places ) {
        out_name = name;
        if ( place->name == "Hive" ) {
            continue;
        }
        std::string pCol = this->get_place_column(name);
        std::string pRow = this->get_place_row(name);
        if ( DEBUG )print("pass get_place_column and row");
        if ( place->exit->name == "AntQueen" ) {
            rows += 1;
        }
        if ( !this->webstate["places"].contains(pRow) ) {
            this->webstate["places"][pRow] = R"({})"_json;
        }
        this->set_place_name_by_row_col(pRow, pCol, name);
        if ( DEBUG )print("pass set_place_name_by_row_col");
        // this->images[name] = dict()
    }
    // Add the Hive
    this->set_place_by_name(out_name);
    if ( DEBUG )print("pass set_place_by_name");
    if ( DEBUG )print("this->len(gamestate->beehive->bees) = ", gamestate->beehive->bees.len());
    for ( std::shared_ptr<Bee> bee : gamestate->beehive->bees ) {
        auto data = R"({
                "id": 0,
                "type": "bee"
            })"_json;
        data["id"] = this->currentBeeId;
        print("this->currentBeeId = ", this->currentBeeId);
        this->webstate["places"][gamestate->beehive->name]["insects"].push_back(data);
        this->beeToId[bee] = this->currentBeeId;
        this->currentBeeId += 1;
        if ( DEBUG )print("pass set for loop");
    }
    this->saveState("rows", this->webstate["places"].size());
    // this->saveState("places", this->webstate["places"]);
}

void Gui::update_food() {
    this->saveState("food", this->gamestate->food);
}

void Gui::_update_control_panel(std::shared_ptr<GameState> gamestate) {
    /*  Reflect the game state in the play area.  */
    this->update_food();
    // old_insects = self.insects[:]
    // old_bees = self.bees[:]
    this->bees    = List<int>();
    this->insects = List<int>();
    if ( DEBUG )print("gamestate->places.len()", gamestate->places.size());
    for ( auto [name, place] : gamestate->places ) {
        if ( place->name == "Hive" ) continue;
        if ( DEBUG )print("heelo world!");
        for ( auto bee : place->bees ) {
            if ( bee->health <= 0 ) continue;
            const auto id = this->beeToId[bee];
            this->beeLocations[id] = name;
            if ( DEBUG )print("add ", name, " to beeLocations");
            if ( !this->bees.has(id) )
                this->bees.append(id);
        }

        if ( DEBUG )print("name = ", name);
        std::string pCol = this->get_place_column(name);
        std::string pRow = this->get_place_row(name);
        if ( place->ant == nullptr ) {
            this->webstate["places"][pRow][pCol]["insects"] = json::parse("{}");
            if ( DEBUG )print(place->name, " 的位置上没有ant");
            continue;
        }

        if (! this->insects.has(this->insectToId[place->ant]) ) {
            // Add this ant to our internal list of insects
            this->insects.append(this->insectToId[place->ant]);
        }
        // Ok there is an ant that needs to be drawn here
        this->webstate["places"][pRow][pCol]["insects"] = R"({
                "id": 0,
                "type": "",
                "img": ""
            })"_json;
        this->webstate["places"][pRow][pCol]["insects"]["id"]   = this->insectToId[place->ant];
        this->webstate["places"][pRow][pCol]["insects"]["type"] = place->ant->get_name();
        this->webstate["places"][pRow][pCol]["insects"]["img"]  = this->get_insect_img_file(place->ant->get_name());
        if ( DEBUG )print(place->name, "上有", place->ant->get_name(), this->webstate["places"][pRow][pCol]["insects"]["img"].get<std::string>());
        // Check if it's a container ant

        bool ant_container = place->ant->is_container();
        if ( DEBUG )print("pass ant_container, the bool is ", ant_container, " ");
        this->webstate["places"][pRow][pCol]["insects"]["container"] = ant_container;
        if ( ant_container &&
            std::dynamic_pointer_cast<ContainerAnt>(place->ant)->ant_contained != nullptr) {
            auto ant_contained = std::dynamic_pointer_cast<ContainerAnt>(place->ant)->ant_contained;
            if ( DEBUG )print("pass if judge");
            this->webstate["places"][pRow][pCol]["insects"]["contains"] = json::parse("{}");
            if ( DEBUG )print("pass assign data");
            this->webstate["places"][pRow][pCol]["insects"]["contains"]["type"] = ant_contained->get_name();
            if ( DEBUG )print("pass get_name");
            this->webstate["places"][pRow][pCol]["insects"]["contains"]["img"] = this->get_insect_img_file(ant_contained->get_name());
            if ( DEBUG )print("pass get_insect_img_file");
        }
        if ( DEBUG )print("pass add containeredant");
        // Loop through our bees
        // Save our new bee locations to our game state
    }
    json locations = R"({})"_json;
    for ( auto [key, value] : this->beeLocations )
    {
        locations[std::to_string(key)] = value;
        // print(std::to_string(key), value);
    }
    this->saveState("beeLocations", locations);
}

json Gui::deploy_ant(json data) {
    print("int gui::deploy_ant");
    auto pname = data["pname"].get<std::string>();
    // print("pname = ", pname);
    auto ant   = data["ant"].get<std::string>();
    // print("ant = ", ant);
    std::shared_ptr<Ant> insect = this->gamestate->deploy_ant(pname, ant);
    print("gamestate.deploy_ant('", pname, "', '", ant, "')");
    if ( insect == nullptr ) {
        return R"({
            "error": "Unable to deploy ant"
        })"_json;
    }
    int id = this->currentInsectId;
    // print("enter this->insects append");
    this->insects.append(id);
    // print("pass append");
    this->insectToId[insect] =  id;
    this->currentInsectId    += 1;
    this->_update_control_panel(this->gamestate);
    // print("pass updateState");
    json response_data = R"({
        "success": 1,
        "id": ""
    })"_json;
    response_data["id"] = id;
    print(response_data.dump());
    return response_data;
}

void InsectDeadBehavior::updateGuiState(std::shared_ptr<Insect> insect) {
    print("in updateGuiState", "insect is ", insect->get_name());
    print("this->gui = ", this->gui);
    print("I am ", insect->get_name(), " i have", insect->health, " health");

    if ( insect->get_name() != "Bee" && this->gui->insectToId.find(insect) != this->gui->insectToId.end() ) {
        if ( DEBUG )print("in insectToId list if");
        this->gui->webstate["deadinsects"].push_back(this->gui->insectToId[insect]);
    } else if ( insect->get_name() == "Bee" && this->gui->beeToId.find(std::dynamic_pointer_cast<Bee>(insect)) != this->gui->beeToId.end() ) {
        if ( DEBUG )print("in beetoid list if");
        this->gui->deadbees.append(this->gui->beeToId[std::dynamic_pointer_cast<Bee>(insect)]);
        this->gui->saveState("deadbees", json::array());
        for ( int ele : this->gui->deadbees ) {
            this->gui->webstate["deadbees"].push_back(ele);
        }
    }
    // print("pass updateGuiState");
}

HttpServer::HttpServer():
    ws(httpserver::create_webserver(8090))
{
    auto routine = new RoutineRequest(this);
    this->ws.register_resource("/",  routine, true);
}
void HttpServer::start() {
    this->ws.start(true);
}

int main(const int arg_number, const char **arg_value) {
    HttpServer hs;
    print("start webserver");
    hs.start();
}
