/* https://github.com/reasonml-community/reason-react-example/blob/master/src/todomvc/App.re */
/* https://jaredforsyth.com/posts/a-reason-react-tutorial/#17-rendering-a-list */

type state = {
  todos: list(string),
  newTodo: string,
};

type action =
  | AddTodo
  | ChangeTodo(string)
  | RemoveTodo(int);

let component = ReasonReact.reducerComponent("App");

let rec removeByIndex = (~index = 0, indexToRemove, listOfTodos) =>
  switch(listOfTodos) {
  | [hd, ...tl] => switch(index == indexToRemove) {
    | true => removeByIndex(~index = (index + 1), indexToRemove, tl)
    | false => [hd, ...removeByIndex(~index = (index + 1), indexToRemove, tl)]
    }
  | [] => []
  };

let make = (_children) => {
  ...component,
  initialState: () => {
    todos: ["Make food", "Exercise", "Sleep"],
    newTodo: "",
  },
  reducer: (action, state) => switch(action) {
  | AddTodo => {
      let todos = state.todos @ [state.newTodo];
      ReasonReact.Update({...state, todos});
    }
  | ChangeTodo(todo) => ReasonReact.Update({...state, newTodo: todo})
  | RemoveTodo(todoIndex) => {
      let todos = removeByIndex(~index = 0, todoIndex, state.todos);
      ReasonReact.Update({...state, todos});
    }
  },
  render: self => {
    let { todos } = self.state;
    let deleteTodo = (todoIndex) => self.send(RemoveTodo(todoIndex));
    <div>
      <TodoList todos deleteTodo />
      <input
        value={self.state.newTodo}
        onChange={
          event => {
            self.send(
              ChangeTodo(
                ReactDOMRe.domElementToObj(
                  ReactEventRe.Form.target(event),
                )##value
              ),
            );
          }
        }
      />
      <button
        onClick={
          _event => {
            self.send(AddTodo);
          }
        }
      >
      {ReasonReact.string("Add todo")}
      </button>
    </div>;
  },
};
