let component = ReasonReact.statelessComponent("TodoList");

let make = (~todos, _self) => {
  ...component,
  render: _self =>
    <ul>
      {
        ReasonReact.array(
          Array.of_list(
            List.map((todo) => <Todo todo />, todos)
          )
        )
      }
    </ul>,
};