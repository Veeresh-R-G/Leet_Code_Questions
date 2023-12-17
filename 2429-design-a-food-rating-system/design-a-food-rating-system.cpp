class FoodRatings {

private:

    unordered_map<string, pair<string, int>> foodToCuisine;

    unordered_map<string, set<pair<int, string>>> cuisineToMaxRating;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int N = foods.size();

        for(int i = 0; i < N; i++){
        
            foodToCuisine[foods[i]] = {cuisines[i], ratings[i]};
            cuisineToMaxRating[cuisines[i]].insert({-ratings[i], foods[i]});
        }

    }
    
    void changeRating(string food, int newRating) {
        auto cuisineName = foodToCuisine[food].first;

        auto delIterator = cuisineToMaxRating[cuisineName].find({-foodToCuisine[food].second, food});

        cuisineToMaxRating[cuisineName].erase(delIterator);

        foodToCuisine[food].second = newRating;

        cuisineToMaxRating[cuisineName].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto ans = *cuisineToMaxRating[cuisine].begin();
        return ans.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */