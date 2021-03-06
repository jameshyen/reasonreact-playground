// Generated by BUCKLESCRIPT VERSION 3.0.0, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var TodoList$ReactTemplate = require("./TodoList.bs.js");

var component = ReasonReact.reducerComponent("App");

function removeByIndex(_$staropt$star, indexToRemove, _listOfTodos) {
  while(true) {
    var listOfTodos = _listOfTodos;
    var $staropt$star = _$staropt$star;
    var index = $staropt$star ? $staropt$star[0] : 0;
    if (listOfTodos) {
      var tl = listOfTodos[1];
      var match = index === indexToRemove;
      if (match) {
        _listOfTodos = tl;
        _$staropt$star = /* Some */[index + 1 | 0];
        continue ;
      } else {
        return /* :: */[
                listOfTodos[0],
                removeByIndex(/* Some */[index + 1 | 0], indexToRemove, tl)
              ];
      }
    } else {
      return /* [] */0;
    }
  };
}

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1];
              var deleteTodo = function (todoIndex) {
                return Curry._1(self[/* send */3], /* RemoveTodo */Block.__(1, [todoIndex]));
              };
              return React.createElement("div", undefined, ReasonReact.element(/* None */0, /* None */0, TodoList$ReactTemplate.make(match[/* todos */0], deleteTodo, /* array */[])), React.createElement("input", {
                              value: self[/* state */1][/* newTodo */1],
                              onChange: (function ($$event) {
                                  return Curry._1(self[/* send */3], /* ChangeTodo */Block.__(0, [$$event.target.value]));
                                })
                            }), React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(self[/* send */3], /* AddTodo */0);
                                })
                            }, "Add todo"));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* todos : :: */[
                        "Make food",
                        /* :: */[
                          "Exercise",
                          /* :: */[
                            "Sleep",
                            /* [] */0
                          ]
                        ]
                      ],
                      /* newTodo */""
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (typeof action === "number") {
                var todos = Pervasives.$at(state[/* todos */0], /* :: */[
                      state[/* newTodo */1],
                      /* [] */0
                    ]);
                return /* Update */Block.__(0, [/* record */[
                            /* todos */todos,
                            /* newTodo */state[/* newTodo */1]
                          ]]);
              } else if (action.tag) {
                var todos$1 = removeByIndex(/* Some */[0], action[0], state[/* todos */0]);
                return /* Update */Block.__(0, [/* record */[
                            /* todos */todos$1,
                            /* newTodo */state[/* newTodo */1]
                          ]]);
              } else {
                return /* Update */Block.__(0, [/* record */[
                            /* todos */state[/* todos */0],
                            /* newTodo */action[0]
                          ]]);
              }
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.removeByIndex = removeByIndex;
exports.make = make;
/* component Not a pure module */
