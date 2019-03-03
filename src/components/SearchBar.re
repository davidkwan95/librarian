let component = ReasonReact.statelessComponent("SearchBar");

let make = (~onInputChange, ~onSearch, _children) => {
  ...component,
  render: _self => (
    <>
      <input
        type_="text"
        onChange=(
          event =>
            onInputChange(ReactEvent.Form.target(event)##value)
        )
      />
      <button onClick=(_ => onSearch())>{ReasonReact.string("Search")}</button>
    </>
  )
}
