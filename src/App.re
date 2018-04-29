type state = {
  todos: list(string),
  newTodo: string,
};

type action =
  | AddTodo
  | ChangeTodo(string);

let component = ReasonReact.reducerComponent("App");

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
  },
  render: self => 
    <div>
      <TodoList todos=self.state.todos />
      <input
        value={self.state.newTodo}
        onChange=(
          event => {
            self.send(
              ChangeTodo(
                ReactDOMRe.domElementToObj(
                  ReactEventRe.Form.target(event),
                )##value
              ),
            );
          }
        )
      />
      <button
        onClick=(
          _event => {
            self.send(AddTodo);
          }
        )
      >
      {ReasonReact.string("Add todo")}
      </button>
    </div>,
};
