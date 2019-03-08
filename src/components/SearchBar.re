let component = ReasonReact.statelessComponent("SearchBar");

let make = (~onInputChange, ~onSearch, _children) => {
  ...component,
  render: _self =>
    <div className="input-group">
      <input
        className="form-control"
        type_="text"
        placeholder="Search by book title or author..."
        onChange={event =>
          onInputChange(ReactEvent.Form.target(event)##value)
        }
      />
      <button
        type_="button" className="btn btn-success" onClick={_ => onSearch()}>
        {ReasonReact.string("Search")}
      </button>
    </div>,
};