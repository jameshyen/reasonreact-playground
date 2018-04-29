let component = ReasonReact.statelessComponent("TodoList");

let make = (~todos, ~deleteTodo, _self) => {
  ...component,
  render: _self =>
    <ul>
      {
        ReasonReact.array(
          Array.of_list(
            List.mapi((index, todo) => <Todo todo deleteTodo todoIndex={index} />, todos)
          )
        )
      }
    </ul>,
};