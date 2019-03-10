let component = ReasonReact.statelessComponent("SearchBar");

let handleKeyPress = (keyCode: int, actionSearch) =>
  if (keyCode == 13) {
    actionSearch();
  };

let make = (~onInputChange, ~actionSearch, _children) => {
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
        onKeyPress={event =>
          handleKeyPress(ReactEvent.Keyboard.which(event), actionSearch)
        }
      />
      <button
        type_="button"
        className="btn btn-success"
        onClick={_ => actionSearch()}>
        {ReasonReact.string("Search")}
      </button>
    </div>,
};