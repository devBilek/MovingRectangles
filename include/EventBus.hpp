#pragma once

#include <unordered_map>
#include <vector> 
#include <typeindex>
#include <functional>

class EventBus {
private:
	using HandlerFunc = std::function<void(const void*)>;
	std::unordered_map<std::type_index, std::vector<HandlerFunc>> subscribers;
public:
	template<typename Event>
	void subscribe(std::function<void(const Event&)> handler) {
		auto& handlers = subscribers[typeid(Event)];
		handlers.push_back([handler](const void* e) {
			handler(*static_cast<const Event*>(e));
			});
	}

	template<typename Event>
	void publish(const Event& event) {
		auto it = subscribers.find(typeid(Event));
		if (it != subscribers.end()) {
			for (auto& handler : it->second) {
				handler(&event);
			}
		}
	}
};