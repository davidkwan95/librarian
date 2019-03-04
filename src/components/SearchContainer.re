type state = {
  searchText: string,
  isLoading: bool,
  volumes: VolumeModules.volumes,
};

type action =
  | UpdateSearchText(string)
  | UpdateResults(VolumeModules.volumes)
  | Search;

let component = ReasonReact.reducerComponent("SearchContainer");

let reducer = (action, state) =>
  switch (action) {
    | UpdateSearchText(searchText) => ReasonReact.Update({...state, searchText})
    | UpdateResults(volumes) => ReasonReact.Update({...state, volumes})
    | Search => ReasonReact.UpdateWithSideEffects(
        {...state, isLoading: true},
        (
          _self => {
            let query = _self.state.searchText
            let _ =
              VolumeModules.Api.fetchData(query)
              |> Js.Promise.then_(searchResult => {
                  _self.send(UpdateResults(searchResult))
                  Js.Promise.resolve()
              });
          }
        )
      )
  };

let make = (_children) => {
  ...component,
  initialState: () => {
    isLoading: false,
    volumes: [],
    searchText: "",
  },
  reducer: reducer,
  render: _self => {
    let { volumes } = _self.state;
    <>
      <div className="my-4">
        <SearchBar
          onInputChange=(
            searchText => _self.send(UpdateSearchText(searchText))
          )
          onSearch=(_ => _self.send(Search))
        />
      </div>
      <SearchResult volumes=volumes />
    </>
  }
};
